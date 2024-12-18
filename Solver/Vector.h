#pragma once

#include "Generator.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

namespace miit::data::structures
{
    template <typename T>
    class Vector;

    template <typename T>
    std::wstring ToString(const Vector<T>& vector);

    template <typename T>
    std::wstring ToString(const Vector<T>* vector);

    template <typename T>
    std::wstring ToString(Vector<T>* vector);

    template <typename T>
    class Vector
    {
    public:
        Vector() : m_data(nullptr), m_size(0) {}

        explicit Vector(const std::unique_ptr<miit::data::generators::Generator<T>>& generator)
        {
            m_size = 1;
            m_data = new T[1];
            m_data[0] = generator->generate();
        }

        Vector(
            const size_t size,
            const std::unique_ptr<miit::data::generators::Generator<T>>& generator)
            : m_size(size)
        {
            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; ++i)
            {
                m_data[i] = generator->generate();
            }
        }

        Vector(const std::initializer_list<T> list)
            : m_size(list.size())
        {
            m_data = new T[m_size];
            size_t index = 0;
            for (const auto& value : list)
            {
                m_data[index++] = value;
            }
        }

        Vector(const Vector& other)
            : m_size(other.m_size)
        {
            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
        }

        Vector(Vector&& other) noexcept
            : m_data(other.m_data), m_size(other.m_size)
        {
            other.m_data = nullptr;
            other.m_size = 0;
        }

        ~Vector()
        {
            delete[] m_data;
        }

        size_t size() const
        {
            return m_size;
        }

        T operator[](const int index) const
        {
            return m_data[index];
        }

        T& operator[](const int index)
        {
            return m_data[index];
        }

        Vector& operator=(const Vector& other)
        {
            if (this != &other)
            {
                delete[] m_data;

                m_size = other.m_size;
                m_data = new T[m_size];
                for (size_t i = 0; i < m_size; ++i)
                {
                    m_data[i] = other.m_data[i];
                }
            }
            return *this;
        }

        Vector& operator=(Vector&& other) noexcept
        {
            if (this != &other)
            {
                delete[] m_data;

                m_data = other.m_data;
                m_size = other.m_size;

                other.m_data = nullptr;
                other.m_size = 0;
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, const Vector& vector)
        {
            out << "[ ";
            for (size_t i = 0; i < vector.m_size; ++i)
            {
                out << vector.m_data[i] << (i < vector.m_size - 1 ? ", " : "");
            }
            out << " ]";
            return out;
        }

        friend std::wostream& operator<<(std::wostream& out, const Vector& vector)
        {
            out << L"[ ";
            for (size_t i = 0; i < vector.m_size; ++i)
            {
                out << vector.m_data[i] << (i < vector.m_size - 1 ? L", " : L"");
            }
            out << L" ]";
            return out;
        }

    private:
        T* m_data;
        size_t m_size;
    };

    template <typename T>
    std::wstring ToString(const Vector<T>& vector)
    {
        std::wstringstream ss;
        ss << vector;
        return ss.str();
    }

    template <typename T>
    std::wstring ToString(const Vector<T>* vector)
    {
        if (vector)
        {
            return ToString(*vector);
        }
        return L"null";
    }

    template <typename T>
    std::wstring ToString(Vector<T>* vector)
    {
        return ToString(static_cast<const Vector<T>*>(vector));
    }
}