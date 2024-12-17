#include "CppUnitTest.h"
#include "../Solver/MyExercise.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/IStreamGenerator.h"
#include <vector>
#include "../Solver/Exercise.h"
#include "../Solver/Matrix.h"
#include <cstddef>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace matrixx;

namespace MatrixTests
{
    TEST_CLASS(ExerciseTests)
    {
    public:
        TEST_METHOD(CtorExercise_ValidData_Success)
        {
            RandomGenerator<int> gen(1, 100);
            MyExercise<int> exercise(3, 3, gen);

            Assert::AreEqual(exercise.matrix.getRows(), (size_t)3);
            Assert::AreEqual(exercise.matrix.getCols(), (size_t)3);
        }

        TEST_METHOD(CtorExercise_ValidData_WithGenerator_Success)
        {
            RandomGenerator<int> gen(1, 100);
            MyExercise<int> exercise(4, 4, gen);

            Assert::AreEqual(exercise.matrix.getRows(), (size_t)4);
            Assert::AreEqual(exercise.matrix.getCols(), (size_t)4);
        }

        TEST_METHOD(FillMatrix_ValidData_FillSuccess)
        {
            RandomGenerator<int> gen(1, 100);
            MyExercise<int> exercise(3, 3, gen);

            exercise.fillMatrix();

            Assert::IsTrue(exercise.matrix[0][0] != 0);
            Assert::IsTrue(exercise.matrix[1][1] != 0);
            Assert::IsTrue(exercise.matrix[2][2] != 0);
        }

        TEST_METHOD(Task1_ValidData_TransformMaxElement_Success)
        {
            RandomGenerator<int> gen(1, 100);
            MyExercise<int> exercise(3, 3, gen);

            exercise.matrix[0] = { 1, -10, 3 };
            exercise.matrix[1] = { 5, -6, 9 };
            exercise.matrix[2] = { -4, -2, -8 };

            exercise.Task1();

            Assert::AreEqual(exercise.matrix[0][1], 10);
            Assert::AreEqual(exercise.matrix[1][2], -9);
            Assert::AreEqual(exercise.matrix[2][2], 8);
        }

        TEST_METHOD(Task2_ValidData_InsertRows_Success)
        {
            RandomGenerator<int> gen(1, 100);
            MyExercise<int> exercise(3, 3, gen);

            exercise.matrix[0] = { 1, 2, 3 };
            exercise.matrix[1] = { 4, 5, 6 };
            exercise.matrix[2] = { 7, 8, 9 };

            exercise.Task2();

            Assert::AreEqual(exercise.matrix.getRows(), (size_t)4);
        }
    };

    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(CtorMatrix_ValidData_Success)
        {
            Matrix<int> matrix(3, 3);
            Assert::AreEqual(matrix.getRows(), (size_t)3);
            Assert::AreEqual(matrix.getCols(), (size_t)3);
        }

        TEST_METHOD(CtorMatrix_ValidDataWithInitVal_Success)
        {
            Matrix<int> matrix(3, 3, 5);
            Assert::AreEqual(matrix[0][0], 5);
            Assert::AreEqual(matrix[1][1], 5);
            Assert::AreEqual(matrix[2][2], 5);
        }

        TEST_METHOD(InsertRow_ValidData_Success)
        {
            Matrix<int> matrix(3, 3);
            matrix[0] = { 1, 2, 3 };
            matrix[1] = { 4, 5, 6 };
            matrix[2] = { 7, 8, 9 };

            matrix.insertRow(1, { 10, 11, 12 });

            Assert::AreEqual(matrix.getRows(), (size_t)4);
            Assert::AreEqual(matrix[1][0], 10);
            Assert::AreEqual(matrix[1][1], 11);
            Assert::AreEqual(matrix[1][2], 12);
        }

        TEST_METHOD(PrintMatrix_ValidData_PrintSuccess)
        {
            Matrix<int> matrix(2, 2);
            matrix[0] = { 1, 2 };
            matrix[1] = { 3, 4 };

            matrix.print();
        }
    };

    TEST_CLASS(GeneratorTests)
    {
    public:
        TEST_METHOD(CtorRandomGenerator_ValidData_Success)
        {
            RandomGenerator<int> gen(1, 10);
            Assert::IsTrue(gen.generate() >= 1 && gen.generate() <= 10);
        }

        TEST_METHOD(CtorIStreamGenerator_ValidData_Success)
        {
            std::istringstream input("42");
            IStreamGenerator<int> gen(input);
            Assert::AreEqual(gen.generate(), 42);
        }
    };
}