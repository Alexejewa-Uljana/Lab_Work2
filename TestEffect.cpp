/**
 * @file TestEffect.cpp
 * @brief Contains test cases for the Effect class using Google Test framework.
 */

#include "gtest/gtest.h"
#include "Effect.h"

/**
 * @test DefaultConstructor
 * @brief Tests the default constructor of the Effect class.
 * 
 * Verifies that an Effect object is created with default values for type and value.
 */
TEST(Effect, DefaultConstructor) {
    Effect effect;

    EXPECT_EQ(effect.type, "none");
    EXPECT_EQ(effect.value, 0);
}

/**
 * @test ParameterizedConstructor
 * @brief Tests the parameterized constructor of the Effect class.
 * 
 * Verifies that an Effect object is created with the correct type and value.
 */
TEST(Effect, ParameterizedConstructor) {
    Effect effect("stun", 5);

    EXPECT_EQ(effect.type, "stun");
    EXPECT_EQ(effect.value, 5);
}

/**
 * @test ApplyEffectTest
 * @brief Tests the applyEffect function of the Effect class.
 * 
 * Verifies that applying the effect does not throw any exceptions.
 */
TEST(Effect, ApplyEffectTest) {
    Effect effect("stun", 5);

    effect.applyEffect();

    SUCCEED();
}

