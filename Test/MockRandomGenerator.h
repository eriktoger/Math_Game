#ifndef MOCKRANDOMGENERATOR_H
#define MOCKRANDOMGENERATOR_H

#include <gmock/gmock.h>
#include "include/randomgenerator.h"

class MockRandomGenerator : public RandomGenerator {
public:
    MOCK_METHOD0(randomInt, int());
};

#endif // MOCKRANDOMGENERATOR_H
