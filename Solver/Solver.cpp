/**
* @author Tim Luchterhand
* @date 27.11.24
* @brief
*/

#include "Solver.hpp"

namespace sat {
    Solver::Solver(unsigned numVariables) {}

    bool Solver::addClause(Clause clause) {

    }

    TruthValue Solver::val(Variable x) const {
    }

    bool Solver::satisfied(Literal l) const {
    }

    bool Solver::falsified(Literal l) const {
    }

    bool Solver::assign(Literal l) {
    }

    bool Solver::unitPropagate() {
    }
} // sat