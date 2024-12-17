#pragma once
#include "Generator.h"
#include <random>
#include <type_traits>

namespace matrixx
{
    template <typename T>
    /**
     * @brief Класс RandomGenerator реализует генератор случайных чисел,
     * @tparam T Тип данных, который будет генерироваться (целые или вещественные числа).
     */
    class RandomGenerator : public Generator<T> {
    private:
        std::mt19937 generator;
        typename std::conditional<std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>>::type distribution; 

    public:
        /**
         * @brief Конструктор класса RandomGenerator.
         */
        RandomGenerator(T min, T max)
            : generator(std::random_device{}()), distribution(min, max) {
        }

        /**
         * @brief Генерирует случайное число в заданном диапазоне.
         */
        T generate() override { return distribution(generator); }
    };
}