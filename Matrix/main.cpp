#include <iostream>
#include "../Solver/Matrix.h"
#include "../Solver/ConstantGenerator.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/Exercise.h"

/**
* @brief Точка входа в программу
* @return 0 программа выполнено успешно
*/
int main()
{
    using namespace miit::data::generators;
    using namespace miit::matrix::exercises;

    
    const int rows = 5;
    const int columns = 5;

    
    auto randomGen = std::make_unique<RandomGenerator<int>>(-10, 10);

    
    ConcreteExercise<int> exercise(rows, columns, std::move(randomGen));

   
    exercise.run();

    return 0;
}
