#include "CppUnitTest.h"
#include "../Solver/Matrix.h"
#include "../Solver/ConstantGenerator.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/Exercise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::data::generators;
using namespace miit::data::structures;
using namespace miit::matrix::exercises;

namespace MatrixTests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestMatrixInitialization)
        {
            auto constantGen = std::make_unique<ConstantGenerator<int>>(5);
            Matrix<int> matrix(3, 3, constantGen);

            for (size_t i = 0; i < matrix.rows(); ++i)
            {
                for (size_t j = 0; j < matrix.columns(); ++j)
                {
                    Assert::AreEqual(5, matrix[i][j]);
                }
            }
        }

        TEST_METHOD(TestNegativeToZeroTask)
        {
            auto gen = std::make_unique<ConstantGenerator<int>>(-5);
            Matrix<int> matrix(3, 3, gen);

            ConcreteExercise<int> exercise(3, 3, std::move(gen));

            
            exercise.task_1();

            for (size_t i = 0; i < matrix.rows(); ++i)
            {
                for (size_t j = 0; j < matrix.columns(); ++j)
                {
                    Assert::AreEqual(0, matrix[i][j]);
                }
            }
        }

        TEST_METHOD(TestRemoveColumnsTask)
        {
            Matrix<int> matrix = {
                {10, 3, 6},
                {15, 4, 7},
                {20, 5, 8}
            };

            auto generator = std::make_unique<ConstantGenerator<int>>(0);
            ConcreteExercise<int> exercise(3, 3, std::move(generator));

            
            exercise.task_2();

            
            Assert::AreEqual(static_cast<size_t>(1), matrix.columns());
            for (size_t i = 0; i < matrix.rows(); ++i)
            {
                Assert::AreEqual(3, matrix[i][0]);
            }
        }

    };
}
