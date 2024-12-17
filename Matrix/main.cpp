#include <locale>
#include "..\Solver\RandomGenerator.h"
#include "..\Solver\IStreamGenerator.h"
#include "..\Solver\MyExercise.h"

int main() {
    setlocale(LC_ALL, "RU");

    matrix::RandomGenerator<int> intGen(-100, 100);
    matrix::MyExercise<int> intExercise(3, 3, intGen);

    std::cout << "Matrix with random values (int):\n";
    intExercise.fillMatrix();
    intExercise.printMatrix();

    std::cout << "\nAfter Task1:\n";
    intExercise.Task1();
    intExercise.printMatrix();

    std::cout << "\nAfter Task2:\n";
    intExercise.Task2();
    intExercise.printMatrix();

    std::cout << "\nEnter the values for the 2x2 (double) matrix:\n";
    matrix::IStreamGenerator<double> userInputGen;
    matrix::MyExercise<double> doubleExercise(2, 2, userInputGen);

    doubleExercise.fillMatrix();
    std::cout << "The matrix entered by the user:\n";
    doubleExercise.printMatrix();

    std::cout << "\nAfter Task1:\n";
    doubleExercise.Task1();
    doubleExercise.printMatrix();

    std::cout << "\nAfter Task2:\n";
    doubleExercise.Task2();
    doubleExercise.printMatrix();

    return 0;
}