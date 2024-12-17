#pragma once
#include "Generator.h"
#include <random>
#include <type_traits>

namespace matrix
{
    template <typename T>
    /**
     * @brief ����� RandomGenerator ��������� ��������� ��������� �����,
     * @tparam T ��� ������, ������� ����� �������������� (����� ��� ������������ �����).
     */
    class RandomGenerator : public Generator<T> {
    private:
        std::mt19937 generator;
        typename std::conditional<std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>>::type distribution; 

    public:
        /**
         * @brief ����������� ������ RandomGenerator.
         */
        RandomGenerator(T min, T max)
            : generator(std::random_device{}()), distribution(min, max) {
        }

        /**
         * @brief ���������� ��������� ����� � �������� ���������.
         */
        T generate() override { return distribution(generator); }
    };
}