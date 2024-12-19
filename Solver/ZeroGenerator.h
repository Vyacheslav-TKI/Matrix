#pragma once

#include "ConstantGenerator.h"

namespace miit::data::generators
{
    template <typename T>
    class ZeroGenerator : public ConstantGenerator<T>
    {
    public:
        /**
         * @brief Конструктор по умолчанию
         */
        ZeroGenerator() : ConstantGenerator<T>(T(0)) {}
    };
}
