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
        /**
         * @brief Конструктор с параметром
         * @param value Фиксированное значение, которое будет возвращаться генератором
         */
        explicit ConstantGenerator(const T& value) : value(value) {};

        /**
         * @brief Генерация фиксированного значения
         * @return Фиксированное значение типа T
         */
        T generate() override
        {
            return value;
        }
    };
}