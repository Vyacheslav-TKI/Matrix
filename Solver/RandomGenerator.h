#pragma once

#include "Generator.h"
#include <random>

namespace miit::data::generators
{
    template <typename T>
    class RandomGenerator final : public Generator<T>
    {
    private:
        std::uniform_real_distribution<T> distribution;
        std::mt19937 generator;

    public:
        RandomGenerator(const T min, const T max)
            : distribution(min, max), generator(std::random_device{}()) {
        }

        T generate() override
        {
            return distribution(generator);
        }
    };
}