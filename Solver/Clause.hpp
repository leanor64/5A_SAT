/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief Contains the class Clause that consists of one or more literals
*/

#ifndef CLAUSE_HPP
#define CLAUSE_HPP

#include <vector>
#include <ostream>

#include "basic_structures.hpp"

namespace sat {
    class Clause {
        // Private members here
    public:

        Clause() = default;

        /**
         * CTor
         * @param literals list of literals of the clause
         * @TODO The tests require a single argument constructor. But you can add more arguments with default values
         * @TODO (for example a flag that tells the constructor if the literals are already sorted)
         * @TODO or even further constructors if you want.
         */
        explicit Clause(std::vector<Literal> literals);

        /*
         * @TODO if you want, you can declare additional constructors here
         */


        /**
         * Gets the watcher rank of the given Literal
         * @param l
         * @return 0 if first watcher, 1 if second watcher, -1 if no watcher
         */
        short getRank(Literal l) const;

        /**
         * Sets the given literal as watcher
         * @param l Literal to be the new watcher
         * @param watcherNo number of the watcher to be replaced
         * @return true if setting watcher was successful, false if literal is not contained in clause
         */
        bool setWatcher(Literal l, short watcherNo);


        /**
         * Get the watch literal identified by the given rank
         * @param rank rank of the watcher in {0, 1}
         * @return watch literal
         */
         Literal getWatcherByRank(short rank) const;

        /*
         * For your information: The following two functions (begin and end) enable the class Clause to be used in a
         * range based for-loop (foreach loop)
         * Clause c;
         * for (auto literal : c) { ... }
         * If you don't want to use a std::vector as the literal container, you need to change the return type of the
         * functions
         */

        /**
         * Iterator to first Literal in the clause
         * @return
         */
         auto begin() const -> std::vector<Literal>::const_iterator;
         // change if necessary ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

        /**
         * Past-the-end iterator
         * @return
         */
         auto end() const -> std::vector<Literal>::const_iterator;
         // change if necessary ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

        /**
         * Array subscript operator
         * @param index index for access
         * @return Literal at given index
         */
        const Literal &operator[](long index) const;

        /**
         * Whether the clause is empty
         * @return
         */
         bool isEmpty() const;

        /**
         * size of the clause
         * @return
         */
         std::size_t size() const;

        friend std::ostream &operator<<(std::ostream &, const Clause &);

        /**
         * Whether the other clause contains the same literals (independent of ordering)
         * @param other clause to compare to
         * @return true if both clauses contain exactly the same literals.
         * @TODO for your implementation you need to either sort the literals or implement your own logic for the order
         * @TODO independent comparison
         */
         bool sameLiterals(const Clause &other) const;

    };
}


#endif //CLAUSE_HPP
