/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include <cassert>
#include <algorithm>

#include "Clause.hpp"

namespace sat {
    //TODO implementation here

    Clause::Clause(std::vector<Literal> literals) {

    }

    short Clause::getRank(Literal l) const {

    }

    std::size_t Clause::getIndex(short rank) const {

    }

    bool Clause::setWatcher(Literal l, short watcherNo) {

    }

    auto Clause::begin() const -> std::vector<Literal>::const_iterator {
    }

    auto Clause::end() const -> std::vector<Literal>::const_iterator {
    }

    bool Clause::isEmpty() const {
    }

    const Literal &Clause::operator[](long index) const {
    }

    std::size_t Clause::size() const {
    }

    Literal Clause::getWatcherByRank(short rank) const {

    }

    bool Clause::sameLiterals(const Clause &other) const {
    }

}
