#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Vector.h"
#include "Generator.h"

namespace miit::data::structures
{
    template <typename T>
    class Matrix;

    template <typename T>
    std::wstring ToString(const Matrix<T>& matrix);

    template <typename T>
    std::wstring ToString(const Matrix<T>* matrix);

    template <typename T>
    std::wstring ToString(Matrix<T>* matrix);

    template <typename T>
    class Matrix
    {
    public:
        /**
        * @brief Конструктор
        * @param rows Количество строк в матрице
        * @param columns Количество столбцов в матрице
        * @param generator Указатель на генератор
        */
        Matrix(
            const int rows,
            const int columns,
            const std::unique_ptr<miit::data::generators::Generator<T>>& generator)
            : m_rows(rows), m_columns(columns)
        {
            if (rows < 0 || columns < 0)
            {
                throw std::out_of_range("Rows and columns must not be less then 0!");
            }

            data.resize(m_rows);
            for (size_t i = 0; i < m_rows; ++i)
            {
                data[i] = Vector<T>(m_columns, generator);
            }
        }

        /**
         * @brief Конструктор 
         * @param matrix Вложенный список значений для заполнения матрицы
         */
        Matrix(const std::initializer_list<std::initializer_list<T>> matrix)
            : m_rows(matrix.size()), m_columns(matrix.begin()->size())
        {
            data.reserve(m_rows);
            for (const auto& row : matrix)
            {
                data.emplace_back(row);
            }
        }

        /**
         * @brief Конструктор копирования
         */
        Matrix(const Matrix& other) = default;

        /**
         * @brief Конструктор перемещения
         */
        Matrix(Matrix&& other) noexcept = default;

        /**
         * @brief Оператор присваивания копирование
         */
        Matrix& operator=(const Matrix&) = default;

        /**
         * @brief Оператор присваивания перемещение
         */
        Matrix& operator=(Matrix&&) noexcept = default;

        /**
        * @brief Оператор доступа к строке константый
        * @param index Индекс строки
        * @return Константная ссылка на вектор строки
        */
        const Vector<T>& operator[](const size_t index) const
        {
            return data[index];
        }

        /**
         * @brief Оператор доступа к строке
         * @param index Индекс строки
         * @return Ссылка на вектор строки
         */
        Vector<T>& operator[](const size_t index)
        {
            return data[index];
        }

        /**
         * @brief Получить количество строк в матрице
         * @return Количество строк
         */
        size_t rows() const noexcept
        {
            return m_rows;
        }

        /**
         * @brief Получить количество столбцов в матрице
         * @return Количество столбцов
         */
        size_t columns() const noexcept
        {
            return m_columns;
        }

        /**
         * @brief Получить строку по индексу
         * @param index Индекс строки
         * @return Вектор строки
         */
        Vector<T> row(const size_t index) const
        {
            return data[index];
        }

        /**
         * @brief Получить столбец по индексу
         * @param index Индекс столбца
         * @return Вектор столбца
         */
        Vector<T> column(const size_t index) const
        {
            Vector<T> col(m_rows);
            for (size_t i = 0; i < m_rows; ++i)
            {
                col[i] = data[i][index];
            }
            return col;
        }

        /**
         * @brief Оператор вывода
         * @param out Поток 
         * @param matrix Матрица
         * @return Поток
         */
        friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
        {
            for (const auto& row : matrix.data)
            {
                out << row << "\n";
            }
            return out;
        }

        /**
         * @brief Оператор вывода в поток wostream
         * @param out Поток 
         * @param matrix Матрица 
         * @return Поток 
         */
        friend std::wostream& operator<<(std::wostream& out, const Matrix& matrix)
        {
            for (const auto& row : matrix.data)
            {
                out << row << L"\n";
            }
            return out;
        }

    private:
        std::vector<Vector<T>> data;
        size_t m_rows;
        size_t m_columns;
    };

    /**
     * @brief Сериализация матрицы в строку
     * @param matrix Ссылка на матрицу
     * @return Строковое представление матрицы
     */
    template <typename T>
    std::wstring ToString(const Matrix<T>& matrix)
    {
        std::wstringstream ss;
        ss << matrix;
        return ss.str();
    }

    /**
     * @brief Сериализация матрицы в строку
     * @param matrix Указатель на матрицу
     * @return Строка матрицы
     */
    template <typename T>
    std::wstring ToString(const Matrix<T>* matrix)
    {
        if (matrix)
        {
            return ToString(*matrix);
        }
        return L"null";
    }

    /**
     * @brief Преобразование указателя на матрицу (не константного) в строку
     * @param matrix Указатель на матрицу
     * @return Строка матрицы
     */
    template <typename T>
    std::wstring ToString(Matrix<T>* matrix)
    {
        return ToString(static_cast<const Matrix<T>*>(matrix));
    }
}