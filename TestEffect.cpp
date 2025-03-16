#include "gtest/gtest.h"
#include "Effect.h"

TEST(Effect, DefaultConstructor) {
    Effect effect;
    EXPECT_EQ(effect.type, "none");
    EXPECT_EQ(effect.value, 0);
}

TEST(Effect, ParameterizedConstructor) {
    Effect effect("stun", 5);
    EXPECT_EQ(effect.type, "stun");
    EXPECT_EQ(effect.value, 5);
}

TEST(Effect, ApplyEffectTest) {
    Effect effect("stun", 5);
    effect.applyEffect();
    SUCCEED();
}

