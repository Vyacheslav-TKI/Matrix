#include <iostream>
#include "../Solver/Matrix.h"
#include "../Solver/ConstantGenerator.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/Exercise.h"

int main()
{
    using namespace miit::data::generators;
    using namespace miit::matrix::exercises;

    
    const size_t rows = 5;
    const size_t columns = 5;

    
    auto randomGen = std::make_unique<RandomGenerator<int>>(-10, 10);

    
    ConcreteExercise<int> exercise(rows, columns, std::move(randomGen));

   
    exercise.run();

    return 0;
}
