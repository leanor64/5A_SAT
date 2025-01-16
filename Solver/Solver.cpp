/**
* @author Tim Luchterhand
* @date 27.11.24
* @brief
*/

#include "Solver.hpp"
#include "util/exception.hpp"
#include <iostream>

namespace sat {
    
    Solver::Solver(unsigned numVariables) {
        std::vector<TruthValue> mod(numVariables, sat::TruthValue::Undefined);
        model = mod;
        std::vector<std::vector<ClausePointer>> wb(numVariables*2);
        watchedBy = wb;

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
            bool edited = false;
            for (Literal unitL : unitLiterals) {
                Literal w1 = c->getWatcherByRank(0);
                Literal w2 = c->getWatcherByRank(1);

                if (satisfied(w1) || satisfied(w2) ){
                    newClauses.emplace_back(Clause({unitL}));
                    edited = true;
                } else if (falsified(w1) || falsified(w2) ) {
                    std::vector<Literal> lits ;
                    for (Literal l: *c){
                        if (l != unitL.negate()){
                            lits.emplace_back(l);
                        }
                    }
                    newClauses.emplace_back(Clause(lits));
                    edited = true;
                }
            }
            if (!edited) {
                newClauses.emplace_back(*c);
            }
        }
        //:std::cout << newClauses.size() << " : Size of newClauses"<< std::endl;
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

    bool Solver::unitPropagate(Literal l){
        for (ClausePointer &c : watchedBy.at(l.get())){
            short r = c->getRank(l);
            size_t start = c->getIndex(r);
            size_t i = c->getIndex(r);
            Literal p = (*c)[c->getIndex(1-r)];
            if (!satisfied(p)){
                while (true) {
                    i++;
                    if (i == c->size()){
                        i=0;
                    }
                    if (i == start){
                        break;
                    }
                    if ((*c)[i] != p){
                        if (!falsified((*c)[i])){
                            c->setWatcher((*c)[i], r);
                            break;
                        }
                    }
                }
                if (i == start){
                    if (falsified(p)) {
                        return false;
                    }
                    assign(p);
                }
            }
        }
        return true;
    }


    bool Solver::unitPropagate() {
        size_t toPropagate = 0;
        while (toPropagate < unitLiterals.size()){
            Literal l = unitLiterals[toPropagate].negate();
            bool propagate = unitPropagate(l);
            if (!propagate) {
                return false;
            }
            toPropagate += 1;
        }
        return true;
    }
} // sat