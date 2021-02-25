#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <random>
#include <algorithm>
#include <iostream>
class RandomGenerator
{
   std::random_device device;
   std::mt19937 generator;
   int lower;
   int upper;
   std::uniform_int_distribution<int> distribution;
public:
    RandomGenerator();
    virtual int randomInt();
    void setBounderies(int newLower, int newUpper);
};

#endif // RANDOMGENERATOR_H
