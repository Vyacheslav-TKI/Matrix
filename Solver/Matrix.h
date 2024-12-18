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
        Matrix(
            const size_t rows,
            const size_t columns,
            const std::unique_ptr<miit::data::generators::Generator<T>>& generator)
            : m_rows(rows), m_columns(columns)
        {
            data.resize(m_rows);
            for (size_t i = 0; i < m_rows; ++i)
            {
                data[i] = Vector<T>(m_columns, generator);
            }
        }

        Matrix(const std::initializer_list<std::initializer_list<T>> matrix)
            : m_rows(matrix.size()), m_columns(matrix.begin()->size())
        {
            data.reserve(m_rows);
            for (const auto& row : matrix)
            {
                data.emplace_back(row);
            }
        }

        Matrix(const Matrix& other) = default;
        Matrix(Matrix&& other) noexcept = default;

        Matrix& operator=(const Matrix&) = default;
        Matrix& operator=(Matrix&&) noexcept = default;

        const Vector<T>& operator[](const size_t index) const
        {
            return data[index];
        }

        Vector<T>& operator[](const size_t index)
        {
            return data[index];
        }

        size_t rows() const noexcept
        {
            return m_rows;
        }

        size_t columns() const noexcept
        {
            return m_columns;
        }

        Vector<T> row(const size_t index) const
        {
            return data[index];
        }

        Vector<T> column(const size_t index) const
        {
            Vector<T> col(m_rows);
            for (size_t i = 0; i < m_rows; ++i)
            {
                col[i] = data[i][index];
            }
            return col;
        }

        friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
        {
            for (const auto& row : matrix.data)
            {
                out << row << "\n";
            }
            return out;
        }

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

    template <typename T>
    std::wstring ToString(const Matrix<T>& matrix)
    {
        std::wstringstream ss;
        ss << matrix;
        return ss.str();
    }

    template <typename T>
    std::wstring ToString(const Matrix<T>* matrix)
    {
        if (matrix)
        {
            return ToString(*matrix);
        }
        return L"null";
    }

    template <typename T>
    std::wstring ToString(Matrix<T>* matrix)
    {
        return ToString(static_cast<const Matrix<T>*>(matrix));
    }
}