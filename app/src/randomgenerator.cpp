#include "../include/randomgenerator.h"

RandomGenerator::RandomGenerator()
{
    lower = 0;
    upper = 9;

    generator = std::mt19937(device());
    distribution = std::uniform_int_distribution<int>(lower, upper);
}

int RandomGenerator::randomInt(){
    return distribution(generator);
}

void RandomGenerator::setBounderies(int newLower, int newUpper){

    lower = newLower;
    upper = newUpper;
    if( lower > upper){
        std::swap(lower,upper);
    }

    distribution = std::uniform_int_distribution<int>(lower, upper);
}
