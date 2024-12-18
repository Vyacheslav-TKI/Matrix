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

        virtual std::string title() const noexcept = 0;

        virtual void task_1() = 0;

        virtual void task_2() = 0;

    public:
        explicit Exercise(
            const size_t rows,
            const size_t columns,
            std::unique_ptr<miit::data::generators::Generator<T>> generator,
            std::ostream& out = std::cout)
            : matrix(new miit::data::structures::Matrix<T>(rows, columns, generator)), out(out) {
        }

        virtual ~Exercise()
        {
            delete matrix;
        }

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
        std::string title() const noexcept override
        {
            return "Concrete Matrix Exercise";
        }

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

        void task_2() override
        {
            
            std::vector<size_t> columnsToRemove;

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
