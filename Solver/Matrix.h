#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

namespace matrixx
{
    template <typename T>
    /**
     * @brief Класс Matrix представляет собой двумерный массив произвольного типа.
     * @tparam T Тип данных, который будет храниться в матрице.
     */
    class Matrix {
    private:
        std::vector<std::vector<T>> data;

    public:
        /**
         * @brief Конструктор класса Matrix.
         * @param rows Количество строк в матрице.
         * @param cols Количество столбцов в матрице.
         * @param initVal Значение для инициализации всех элементов матрицы (по умолчанию - типа T).
         */
        Matrix(size_t rows, size_t cols, T initVal = T()) : data(rows, std::vector<T>(cols, initVal)) {}

        /**
         * @brief Оператор доступа к элементам матрицы.
         * @param row Индекс строки, к которой нужно получить доступ.
         * @return std::vector<T>& Ссылка на строку матрицы.
         */
        std::vector<T>& operator[](size_t row) { return data[row]; }

        /**
         * @brief Оператор доступа к элементам матрицы.
         * @param row Индекс строки, к которой нужно получить доступ.
         * @return const std::vector<T>& Константная ссылка на строку матрицы.
         */
        const std::vector<T>& operator[](size_t row) const { return data[row]; }

        /**
         * @brief Получает количество строк в матрице.
         * @return size_t Количество строк в матрице.
         */
        size_t getRows() const { return data.size(); }

        /**
         * @brief Получает количество столбцов в матрице.
         * @return size_t Количество столбцов в матрице.
         */
        size_t getCols() const { return data[0].size(); }

        /**
         * @brief Вставляет строку в матрицу на указанную позицию.
         * @param pos Позиция, на которую нужно вставить строку.
         * @param row Вектор, представляющий строку для вставки.
         */
        void insertRow(size_t pos, const std::vector<T>& row) {
            if (pos <= data.size()) {
                data.insert(data.begin() + pos, row);
            }
        }

        /**
         * @brief Выводит содержимое матрицы на экран.
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
