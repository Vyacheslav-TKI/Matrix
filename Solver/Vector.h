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
        /**
         * @brief Конструктор по умолчанию
         */
        Vector() : m_data(nullptr), m_size(0) {}

        /**
         * @brief Конструктор с генератором
         * @param generator Умный указатель на генератор значений типа T
         */
        explicit Vector(const std::unique_ptr<miit::data::generators::Generator<T>>& generator)
        {
            m_size = 1;
            m_data = new T[1];
            m_data[0] = generator->generate();
        }

        /**
         * @brief Конструктор с размером и генератором
         * @param size Размер вектора
         * @param generator Умный указатель на генератор значений типа T
         */
        Vector(
            const int size,
            const std::unique_ptr<miit::data::generators::Generator<T>>& generator)
            : m_size(size)
        {
            if (size < 0)
            {
                throw std::out_of_range("Size must not be less than 0!");
            }

            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; ++i)
            {
                m_data[i] = generator->generate();
            }
        }

        /**
         * @brief Конструктор
         * @param list Список инициализации с элементами типа T
         */
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

        /**
         * @brief Конструктор копирования
         * @param other Вектор, который нужно скопировать
         */
        Vector(const Vector& other)
            : m_size(other.m_size)
        {
            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
        }

        /**
        * @brief Конструктор перемещения
        * @param other Вектор, который нужно переместить
        */
        Vector(Vector&& other) noexcept
            : m_data(other.m_data), m_size(other.m_size)
        {
            other.m_data = nullptr;
            other.m_size = 0;
        }

        /**
        * @brief Деструктор
        */
        ~Vector()
        {
            delete[] m_data;
        }

        /**
         * @brief Получить размер вектора
         * @return Размер вектора
         */
        size_t size() const
        {
            return m_size;
        }

        /**
         * @brief Оператор доступа к элементу (чтение)
         * @param index Индекс элемента
         * @return Значение элемента по указанному индексу
         */
        T operator[](const int index) const
        {
            return m_data[index];
        }

        /**
         * @brief Оператор доступа к элементу (запись)
         * @param index Индекс элемента
         * @return Ссылка на элемент по указанному индексу
         */
        T& operator[](const int index)
        {
            return m_data[index];
        }

        /**
         * @brief Оператор присваивания (копирование)
         * @param other Вектор, значения которого будут скопированы
         * @return Ссылка на текущий объект
         */
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

        /**
         * @brief Оператор присваивания (перемещение)
         * @param other Вектор, значения которого будут перемещены
         * @return Ссылка на текущий объект
         */
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

        /**
         * @brief Оператор вывода
         * @param out Поток
         * @param vector Вектор, который нужно вывести
         * @return Ссылка на поток
         */
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

        /**
        * @brief Оператор вывода в поток std::wostream
        * @param out Поток
        * @param vector Вектор, который нужно вывести
        * @return Ссылка на поток
        */
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

    /**
     * @brief Сериализация вектора в строку
     * @tparam T Тип элементов вектора
     * @param vector Вектор для преобразования
     * @return Строка, представляющая содержимое вектора
     */
    template <typename T>
    std::wstring ToString(const Vector<T>& vector)
    {
        std::wstringstream ss;
        ss << vector;
        return ss.str();
    }

    /**
    * @brief Преобразование указателя на вектор в строку
    * @tparam T Тип элементов вектора
    * @param vector Указатель на вектор
    * @return Строка вектора
    */
    template <typename T>
    std::wstring ToString(const Vector<T>* vector)
    {
        if (vector)
        {
            return ToString(*vector);
        }
        return L"null";
    }

    /**
     * @brief Преобразование указателя на вектор (не константного) в строку 
     * @tparam T Тип элементов вектора
     * @param vector Указатель на вектор
     * @return Строка вектора
     */
    template <typename T>
    std::wstring ToString(Vector<T>* vector)
    {
        return ToString(static_cast<const Vector<T>*>(vector));
    }
}