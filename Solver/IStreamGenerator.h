#pragma once
#include "Generator.h"
#include <iostream>

namespace matrix
{
    template <typename T>
    /**
     * @brief ����� IStreamGenerator ��������� ��������� �������� �� �������� ������.
     * @tparam T ��� ������, ������� ����� ������������ ����� IStreamGenerator.
     */
    class IStreamGenerator : public Generator<T> {
    private:
        std::istream& inputStream;

    public:
        /**
         * @brief ����������� ������ IStreamGenerator.
         * @param in ������ �� ������� ����� (�� ��������� std::cin).
         */
        IStreamGenerator(std::istream& in = std::cin) : inputStream(in) {}

        /**
         * @brief ���������� �������� ���� T, �������� ��� �� �������� ������.
         * @return T ��������� �������� ���� T �� �������� ������.
         */
        T generate() override {
            T value;
            inputStream >> value;
            return value;
        }
    };
}