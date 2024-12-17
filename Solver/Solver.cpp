/**
* @author Tim Luchterhand
* @date 27.11.24
* @brief
*/

#include "Solver.hpp"
#include "util/exception.hpp"

namespace sat {
    
    Solver::Solver(unsigned numVariables) {
        std::vector<TruthValue> mod(numVariables, sat::TruthValue::Undefined);
        model = mod;
    }   

    bool Solver::addClause(Clause clause) {
        bool res = false;
        if (clause.size() == 1) {
            assign(*clause.begin())
        } else if (!clause.isEmpty()) {
            auto ptr = std::make_shared<Clause>(clause); 
            clauses.emplace_back(ptr);
            Literal l1 = clause.getWatcherByRank(0);
            Literal l2 = clause.getWatcherByRank(1);
            watchedBy.at(l1.get()).emplace_back(ptr);
            watchedBy.at(l2.get()).emplace_back(ptr);
            res = true;
        }
        return res;
    }

    auto Solver::rebase() const -> std::vector<Clause> {
        std::vector<Clause> newClauses;
        for (TruthValue val : model) {
            if () {
                
            }
        }


        return newClauses;
    }

    TruthValue Solver::val(Variable x) const { 
        return model[x.get()];
    }

    bool Solver::satisfied(Literal l) const {
        return l.sign() == 1;
    }

    bool Solver::falsified(Literal l) const {
        throw NOT_IMPLEMENTED;
    }

    bool Solver::assign(Literal l) {
        throw NOT_IMPLEMENTED;
    }

    bool Solver::unitPropagate() {
        throw NOT_IMPLEMENTED;
    }
} // sat