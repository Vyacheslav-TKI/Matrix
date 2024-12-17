#pragma once
#include "Generator.h"
#include <random>
#include <type_traits>

namespace matrix
{
    template <typename T>
    /**
     * @brief  ласс RandomGenerator реализует генератор случайных чисел,
     * @tparam T “ип данных, который будет генерироватьс€ (целые или вещественные числа).
     */
    class RandomGenerator : public Generator<T> {
    private:
        std::mt19937 generator;
        typename std::conditional<std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>>::type distribution; 

    public:
        /**
         * @brief  онструктор класса RandomGenerator.
         */
        RandomGenerator(T min, T max)
            : generator(std::random_device{}()), distribution(min, max) {
        }

        /**
         * @brief √енерирует случайное число в заданном диапазоне.
         */
        T generate() override { return distribution(generator); }
    };
}