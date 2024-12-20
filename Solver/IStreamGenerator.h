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
        /**
         * @brief Конструктор с параметром потока
         * @param in Поток ввода
         */
        explicit IStreamGenerator(std::istream& in = std::cin) : in(in) {}

        /**
         * @brief Генерация значения из входного потока
         * @return Считанное значение типа T.
         */
        T generate() override
        {
            T value;
            in >> value;
            return value;
        }
    };
}