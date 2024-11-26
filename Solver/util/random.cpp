/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include "random.hpp"

namespace sat {
    RNG::RNG() : el(rd()) {}

    RNG & RNG::get() {
        static RNG rng;
        return rng;
    }

    void RNG::setSeed(unsigned seed) {
        el.seed(seed);
    }
}
