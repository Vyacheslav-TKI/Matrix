#pragma once

#include "ConstantGenerator.h"

namespace miit::data::generators
{
    template <typename T>
    class ZeroGenerator : public ConstantGenerator<T>
    {
    public:
        ZeroGenerator() : ConstantGenerator<T>(T(0)) {}
    };
}
