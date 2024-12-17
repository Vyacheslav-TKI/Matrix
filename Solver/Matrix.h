#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

namespace matrix
{
    template <typename T>
    /**
     * @brief ����� Matrix ������������ ����� ��������� ������ ������������� ����.
     * @tparam T ��� ������, ������� ����� ��������� � �������.
     */
    class Matrix {
    private:
        std::vector<std::vector<T>> data;

    public:
        /**
         * @brief ����������� ������ Matrix.
         * @param rows ���������� ����� � �������.
         * @param cols ���������� �������� � �������.
         * @param initVal �������� ��� ������������� ���� ��������� ������� (�� ��������� - ���� T).
         */
        Matrix(size_t rows, size_t cols, T initVal = T()) : data(rows, std::vector<T>(cols, initVal)) {}

        /**
         * @brief �������� ������� � ��������� �������.
         * @param row ������ ������, � ������� ����� �������� ������.
         * @return std::vector<T>& ������ �� ������ �������.
         */
        std::vector<T>& operator[](size_t row) { return data[row]; }

        /**
         * @brief �������� ������� � ��������� �������.
         * @param row ������ ������, � ������� ����� �������� ������.
         * @return const std::vector<T>& ����������� ������ �� ������ �������.
         */
        const std::vector<T>& operator[](size_t row) const { return data[row]; }

        /**
         * @brief �������� ���������� ����� � �������.
         * @return size_t ���������� ����� � �������.
         */
        size_t getRows() const { return data.size(); }

        /**
         * @brief �������� ���������� �������� � �������.
         * @return size_t ���������� �������� � �������.
         */
        size_t getCols() const { return data[0].size(); }

        /**
         * @brief ��������� ������ � ������� �� ��������� �������.
         * @param pos �������, �� ������� ����� �������� ������.
         * @param row ������, �������������� ������ ��� �������.
         */
        void insertRow(size_t pos, const std::vector<T>& row) {
            if (pos <= data.size()) {
                data.insert(data.begin() + pos, row);
            }
        }

        /**
         * @brief ������� ���������� ������� �� �����.
         */
        void print() const {
            for (const auto& row : data) {
                for (const auto& elem : row) {
                    std::cout << std::setw(5) << elem << " ";
                }
                std::cout << "\n";
            }
        }
    };
}