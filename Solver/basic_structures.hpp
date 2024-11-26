/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief Contains the basic structures variable and literal
*/

#ifndef BASIC_STRUCTURES_HPP
#define BASIC_STRUCTURES_HPP

/* These are only the declarations of the classes and their members
 * @TODO implementation in basic_structures.cpp
 */

namespace sat {

    /**
     * Structure representing a binary variable in a CNF-SAT problem
     */
    class  Variable {
        // Private members here
    public:
        /**
         * CTor
         * @param val variable number (name of the variable)
         */
        Variable(unsigned val);

        /**
         * gets the underlying variable number
         * @return
         */
        unsigned get() const;

        /**
         * Compares the underlying variable identifier
         * @return True if both variables are the same (have the same identifier)
         */
        bool operator==(const Variable &other) const;
    };

    /**
     * Structure representing a literal in a CNF-SAT problem. A literal of variable x is either x or ¬x
     */
    class Literal {
        // Private members here
    public:
        /**
         * CTor
         * @param val Literal identifier. A literal is related to a variable by dividing its identifier by two. An even
         * identifier stands for a negative literal, an odd one for a positive
         * see also sat::pos and sat::neg
         */
        Literal(unsigned val);

        /**
         * Gets the underlying literal identifier
         * @return the literal identifier
         */
        unsigned get() const;

        /**
         * Gets the negated literal
         * @return the negated literal
         */
        Literal negate() const;

        /**
         * Gets the sign of the literal
         * @return -1 if negative literal, +1 else
         */
        short sign() const;

        /**
         * Compares underlying literal identifiers
         * @return True if both literals are exactly the same (sign and variable)
         */
        bool operator==(const Literal &) const;
    };

    /**
     * Creates the positive Literal for a given variable
     * @param x Variable for which to create the literal
     * @return positive literal of x
     */
    Literal pos(Variable x);

    /**
     * Creates the negative Literal for a given variable
     * @param x Variable for which to create the literal
     * @return negative literal of x
     */
    Literal neg(Variable x);

    /**
     * Gets the corresponding Variable of a Literal
     * @param l
     * @return Variable of given Literal
     */
    Variable var(Literal l);

}

#endif //BASIC_STRUCTURES_HPP
