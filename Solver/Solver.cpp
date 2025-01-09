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
            assign(*clause.begin());
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
        std::vector<Clause> newClauses ;
        
        for (ClausePointer c : clauses) {
            for (Literal unitL : unitLiterals) {
                if (c->getWatcherByRank(0)==unitL || c->getWatcherByRank(1)==unitL ){
                    newClauses.emplace_back(Clause({unitL}));
                } else if (c->getWatcherByRank(0)==unitL.negate() || c->getWatcherByRank(1)==unitL.negate() ) {
                    std::vector<Literal> lits ;
                    for (Literal l: *c){
                        if (l != unitL.negate()){
                            lits.emplace_back(l);
                        }
                    }
                    newClauses.emplace_back(Clause(lits));
                } else {
                    newClauses.emplace_back(*c);
                }
                
        
            }
        }

        return newClauses;
    }

    TruthValue Solver::val(Variable x) const { 
        return model[x.get()];
    }

    bool Solver::satisfied(Literal l) const {
        if (l.sign() == 1) {
            return val(var(l)) == sat::TruthValue::True;
        } else {
            return val(var(l)) == sat::TruthValue::False;
        }
    }

    bool Solver::falsified(Literal l) const {
        if (l.sign() == -1) {
            return val(var(l)) == sat::TruthValue::True;
        } else {
            return val(var(l)) == sat::TruthValue::False;
        }
    }

    bool Solver::assign(Literal l) {
        if (l.sign() == -1 && val(var(l))!=sat::TruthValue::Undefined){ 
            return false;
        } else {
            if (l.sign() == 1) {
                model[var(l).get()]=sat::TruthValue::True;
            } else {
                model[var(l).get()]=sat::TruthValue::False;
            }
            unitLiterals.push_back(l);
            return true;
        }
    }

    bool Solver::unitPropagate() {
        throw NOT_IMPLEMENTED;
    }
} // sat