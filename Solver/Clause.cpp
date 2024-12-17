/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include <cassert>
#include <algorithm>

#include "Clause.hpp"
#include "util/exception.hpp"

namespace sat {

    Clause::Clause(std::vector<Literal> literals) {
        lits=literals;
        index1=0;
        index2=1;
    }

    short Clause::getRank(Literal l) const {
        if (lits.at(index1) == l.get()) {
            return 0;
        } else if (lits.at(index2) == l.get()) {
            return 1;
        } else {
            return -1;
        }
    }

    std::size_t Clause::getIndex(short rank) const {
        size_t res = -1;
        if(rank == 0) {
            res = index1;
        } else if (rank == 1) {
            res = index2;
        }
        return res;
    }

    bool Clause::setWatcher(Literal l, short watcherNo) {
        bool ret = false;
        auto res = std::ranges::find(lits, l);
        if (res != lits.end()) {
            int ind = res - lits.begin();
            if (watcherNo == 0) {
                index1 = ind;
                ret = true;
            } else if (watcherNo == 1) {
                index2 = ind;
                ret = true;
            }
        } 
        return ret;
    }

    auto Clause::begin() const -> std::vector<Literal>::const_iterator {
        return lits.begin();
    }

    auto Clause::end() const -> std::vector<Literal>::const_iterator {
        return lits.end();
    }

    bool Clause::isEmpty() const {
        return lits.empty();
    }

    Literal Clause::operator[](std::size_t index) const {
        return(lits.at(index));
    }

    std::size_t Clause::size() const {
        return lits.size();
    }

    Literal Clause::getWatcherByRank(short rank) const {
        if (rank == 0) {
            return lits.at(index1);
        } else {
            return lits.at(index2);
        }
    }

    bool Clause::sameLiterals(const Clause &other) const {
        bool res = true;
        if (lits.size() == other.size()) {
            for (unsigned int i = 0; i < lits.size(); i++) {
                if (std::count(other.begin(), other.end(),lits.at(i)) != 0) {
                    continue; 
                } else {
                    res = false;
                    break;
                }
            }
        } else {
            res = false;
        }
        return res;
    }

}
