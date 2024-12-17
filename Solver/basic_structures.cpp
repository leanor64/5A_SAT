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
        var = val;
    }

    unsigned Variable::get() const {
        return var;
    }

    bool Variable::operator==(Variable other) const {
        return (var == other.get());
    }

    Literal::Literal(unsigned val) {
        lit=val;
    }

    unsigned Literal::get() const {
        return lit;
    }

    Literal Literal::negate() const {
        // var*2 + 1 => impair donc positif
        if (lit%2) { 
            return lit-1;
        } else {
            return lit+1;
        }
    }

    short Literal::sign() const {
        if (lit%2) { 
            return +1;
        } else {
            return -1;
        }
    }

    bool Literal::operator==(Literal other) const {
        return (lit == other.get()) ;
    }

    Literal pos(Variable x) {
        return 2*x.get()+1;
    }

    Literal neg(Variable x) {
        return 2*x.get();
    }

    Variable var(Literal l) {
        return l.get()/2;
    }
}
