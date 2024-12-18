#pragma once

#include "Generator.h"

namespace miit::data::generators
{
    template <typename T>
    class ConstantGenerator : public Generator<T>
    {
    private:
        T value;

    public:
        explicit ConstantGenerator(const T& value) : value(value) {}

        T generate() override
        {
            return value;
        }
    };
}