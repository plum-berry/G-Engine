// Random.h
#pragma once
#include <random>

namespace Random {
    inline std::mt19937& Engine() {
        static std::mt19937 rng{std::random_device{}()};
        return rng;
    }
    inline float Range(float lo, float hi) {
        return std::uniform_real_distribution<float>(lo, hi)(Engine());
    }
}