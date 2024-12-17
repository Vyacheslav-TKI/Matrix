#pragma once
#include "Generator.h"
#include <iostream>

namespace matrix
{
    template <typename T>
    /**
     * @brief Класс IStreamGenerator реализует генератор значений из входного потока.
     * @tparam T Тип данных, которые будет генерировать класс IStreamGenerator.
     */
    class IStreamGenerator : public Generator<T> {
    private:
        std::istream& inputStream;

    public:
        /**
         * @brief Конструктор класса IStreamGenerator.
         * @param in Ссылка на входной поток (по умолчанию std::cin).
         */
        IStreamGenerator(std::istream& in = std::cin) : inputStream(in) {}

        /**
         * @brief Генерирует значение типа T, считывая его из входного потока.
         * @return T Считанное значение типа T из входного потока.
         */
        T generate() override {
            T value;
            inputStream >> value;
            return value;
        }
    };
}