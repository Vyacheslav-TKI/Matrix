#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::data::generators
{
    template <typename T>
    class IStreamGenerator final : public Generator<T>
    {
    private:
        std::istream& in;

    public:
        explicit IStreamGenerator(std::istream& in = std::cin) : in(in) {}

        T generate() override
        {
            T value;
            in >> value;
            return value;
        }
    };
}