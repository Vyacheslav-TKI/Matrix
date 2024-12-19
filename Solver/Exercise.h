#pragma once

#include "Generator.h"
#include "Matrix.h"

#include <iostream>
#include <memory>

namespace miit::matrix::exercises
{
    template <typename T>
    class Exercise
    {
    protected:
        miit::data::structures::Matrix<T>* matrix;
        std::ostream& out;

        /**
         * @brief Получает заголовок упражнения
         * @return Строка с названием упражнения
         */
        virtual std::string title() const noexcept = 0;

        /**
        * @brief Виртуальное первое задание
        */
        virtual void task_1() = 0;

        /**
        * @brief Виртуальное второе задание
        */
        virtual void task_2() = 0;

    public:
        /**
        * @brief Конструктор
        * @param rows Количество строк в матрице
        * @param columns Количество столбцов в матрице
        * @param generator Указатель на генератор для инициализации элементов матрицы
        * @param out Поток вывода (по умолчанию std::cout)
        */
        explicit Exercise(
            const int rows,
            const int columns,
            std::unique_ptr<miit::data::generators::Generator<T>> generator,
            std::ostream& out = std::cout)
            : matrix(new miit::data::structures::Matrix<T>(rows, columns, generator)), out(out) {
        }

        /**
        * @brief Деструктор
        */
        virtual ~Exercise()
        {
            delete matrix;
        }

        /**
        * @brief Запускает выполнение всех заданий
        */
        void run()
        {
            out << "Running exercise: " << title() << "\n";
            out << "Original Matrix:\n" << *matrix << "\n";

            out << "Task 1:\n";
            task_1();
            out << *matrix << "\n";

            out << "Task 2:\n";
            task_2();
            out << *matrix << "\n";
        }
    };

    template <typename T>
    class ConcreteExercise : public Exercise<T>
    {
    protected:
        /**
         * @brief Получить заголовок упражнения
         * @return Строка
         */
        std::string title() const noexcept override
        {
            return "Concrete Matrix Exercise";
        }

        /**
         * @brief Все отрицательные элементы матрицы заменяются на 0
         */
        void task_1() override
        {
          
            for (size_t col = 0; col < this->matrix->columns(); ++col)
            {
                for (size_t row = 0; row < this->matrix->rows(); ++row)
                {
                    if ((*this->matrix)[row][col] < 0)
                    {
                        (*this->matrix)[row][col] = 0;
                    }
                }
            }
        }

        /**
        * @brief Удаляет столбцы, содержащие элементы, кратные 5
        */
        void task_2() override
        {
            
            Vector<T> columnsToRemove;

            for (size_t col = 0; col < this->matrix->columns(); ++col)
            {
                for (size_t row = 0; row < this->matrix->rows(); ++row)
                {
                    if ((*this->matrix)[row][col] % 5 == 0)
                    {
                        columnsToRemove.push_back(col);
                        break;
                    }
                }
            }

            auto newMatrix = miit::data::structures::Matrix<T>(this->matrix->rows(), this->matrix->columns() - columnsToRemove.size(), nullptr);
            size_t newColIndex = 0;

            for (size_t col = 0; col < this->matrix->columns(); ++col)
            {
                if (std::find(columnsToRemove.begin(), columnsToRemove.end(), col) == columnsToRemove.end())
                {
                    for (size_t row = 0; row < this->matrix->rows(); ++row)
                    {
                        newMatrix[row][newColIndex] = (*this->matrix)[row][col];
                    }
                    ++newColIndex;
                }
            }

            delete this->matrix;
            this->matrix = new miit::data::structures::Matrix<T>(std::move(newMatrix));
        }

    public:
        using Exercise<T>::Exercise;
    };
}
