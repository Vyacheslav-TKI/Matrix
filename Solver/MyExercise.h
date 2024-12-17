#pragma once
#include "Exercise.h"
#include <algorithm>
#include <cmath>

namespace matrix {
    template <typename T>
    class MyExercise : public Exercise<T> {
    public:
        MyExercise(size_t rows, size_t cols, Generator<T>& gen)
            : Exercise<T>(rows, cols, gen) {}

        void setGenerator(Generator<T>& gen) {
            this->generator = &gen; 
            this->matrix.fillWithGenerator(*this->generator);
        }

        /**
         * @brief ������ 1: �������� ������������� ������� ������� ������� �� ����.
         */
        void Task1() override {
            size_t rows = this->matrix.getRows();
            size_t cols = this->matrix.getCols();

            for (size_t col = 0; col < cols; ++col) {
                for (size_t row = 0; row < rows; ++row) {
                    if (this->matrix(row, col) < 0) {
                        this->matrix(row, col) = 0;
                    }
                }
            }
        }

        /**
         * @brief ������ 2: ������� �� ������� �������, ���������� �������, ������� 5.
         */
        void Task2() override {
            size_t rows = this->matrix.getRows();
            size_t cols = this->matrix.getCols();

            for (size_t col = 0; col < cols; ) { 
                bool hasMultipleOf5 = false;

                
                for (size_t row = 0; row < rows; ++row) {
                    if (this->matrix(row, col) % 5 == 0) {
                        hasMultipleOf5 = true;
                        break;
                    }
                }

                if (hasMultipleOf5) {
                    this->matrix.removeCol(col); // �������� �������
                    --cols; // ��������� ���������� ��������
                }
                else {
                    ++col; // ��������� � ���������� �������
                }
            }
        }
    };
}
