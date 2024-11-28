/**
* @author Tim Luchterhand
* @date 27.11.24
* @brief Testing utilities
*/

#ifndef TESTING_UTILS_HPP
#define TESTING_UTILS_HPP

#include <unordered_set>

#include "util/concepts.hpp"
#include "basic_structures.hpp"
#include "Clause.hpp"

/**
 * @brief Namespace containing testing helpers
 */
namespace test {
    template<typename T>
    struct Hash {
        auto operator()(const T &t) const noexcept {
            using SubT = decltype(t.get());
            return std::hash<SubT>{}(t.get());
        }
    };

    using LitSet = std::unordered_set<sat::Literal, Hash<sat::Literal>>;

    template<sat::concepts::typed_range<sat::Literal> Literals>
    bool setsEqual(const Literals &literals, LitSet gt) {
        for (const auto &literal: literals) {
            if (not gt.contains(literal)) {
                return false;
            }

            gt.erase(literal);
        }

        return gt.empty();
    }

    template<sat::clause_like Cl, sat::clause_like Cl_>
    bool findClause(const Cl &clause, const std::vector<Cl_> &clauses) {
        std::vector literals(clause.begin(), clause.end());
        std::ranges::sort(literals, {}, [](auto lit) { return lit.get(); });
        auto res = std::ranges::find_if(clauses, [&literals](const auto &c) {
            std::vector clauseLits(c.begin(), c.end());
            std::ranges::sort(clauseLits, {}, [](auto lit) { return lit.get(); });
            return clauseLits == literals;
        });

        return res != clauses.end();
    }
}

#endif //TESTING_UTILS_HPP
