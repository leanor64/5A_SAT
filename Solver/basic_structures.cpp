/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include "basic_structures.hpp"
#include "util/exception.hpp"

namespace sat {
    // @TODO implementation here


    Variable::Variable(unsigned val) {
        throw NOT_IMPLEMENTED;
    }

    unsigned Variable::get() const {
        throw NOT_IMPLEMENTED;
    }

    bool Variable::operator==(Variable other) const {
        throw NOT_IMPLEMENTED;
    }

    Literal::Literal(unsigned val) {
        throw NOT_IMPLEMENTED;
    }

    unsigned Literal::get() const {
        throw NOT_IMPLEMENTED;
    }

    Literal Literal::negate() const {
        throw NOT_IMPLEMENTED;
    }

    short Literal::sign() const {
        throw NOT_IMPLEMENTED;
    }

    bool Literal::operator==(Literal other) const {
        throw NOT_IMPLEMENTED;
    }

    Literal pos(Variable x) {
        throw NOT_IMPLEMENTED;
    }

    Literal neg(Variable x) {
        throw NOT_IMPLEMENTED;
    }

    Variable var(Literal l) {
        throw NOT_IMPLEMENTED;
    }
}
