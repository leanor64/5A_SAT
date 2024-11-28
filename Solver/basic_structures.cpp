/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include "basic_structures.hpp"
#include "util/random.hpp"

namespace sat {
    // @TODO implementation here


    Variable::Variable(unsigned val) {
    }

    unsigned Variable::get() const {
    }

    bool Variable::operator==(const Variable &other) const {
    }

    Literal::Literal(unsigned val) {
    }

    unsigned Literal::get() const {
    }

    Literal Literal::negate() const {
    }

    short Literal::sign() const {
    }

    bool Literal::operator==(const Literal &other) const {
    }

    Literal pos(Variable x) {
    }

    Literal neg(Variable x) {
    }

    Variable var(Literal l) {
    }
}
