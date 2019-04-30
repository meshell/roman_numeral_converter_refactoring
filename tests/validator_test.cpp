#include "roman_validator/validator.h"
#include <catch.hpp>

// see https://projecteuler.net/about=roman_numerals

namespace {

class RomanValidatorTestsFixture {
protected:
    roman_numerals::RomanNumberValidator validator{};
};

TEST_CASE_METHOD(RomanValidatorTestsFixture, "Digits I, V, X, L, C, D, M are allowed", "[validator]") {
    CHECK(validator.is_valid("I"));
    CHECK(validator.is_valid("V"));
    CHECK(validator.is_valid("X"));
    CHECK(validator.is_valid("L"));
    CHECK(validator.is_valid("C"));
    CHECK(validator.is_valid("D"));
    CHECK(validator.is_valid("M"));
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "Digits other than I, V, X, L, C, D, M are not allowed", "[validator]") {
    CHECK_FALSE(validator.is_valid("A"));
    CHECK_FALSE(validator.is_valid("1"));
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "M, C, and X cannot be equalled or exceeded by smaller denominations", "[validator]") {
    CHECK(validator.is_valid("IIIIIIIII")); // 9
    CHECK_FALSE(validator.is_valid("IIIIIIIIII")); // 10 (X)
    CHECK_FALSE(validator.is_valid("VIIIII")); // 10 (X)

    CHECK(validator.is_valid("XXXXXXXXX")); // 90
    CHECK_FALSE(validator.is_valid("XXXXXXXXXX")); // 100 (C)
    CHECK_FALSE(validator.is_valid("LXXXXX")); // 100 (C)
    CHECK_FALSE(validator.is_valid("LXXXXXIII")); // 103 (C)

    CHECK(validator.is_valid("CCCCCCCCC")); // 900
    CHECK_FALSE(validator.is_valid("CCCCCCCCCC")); // 1000 (M)
    CHECK_FALSE(validator.is_valid("DCCCCC")); // 1000 (M)
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "MCM is valid", "") {
    REQUIRE(validator.is_valid("MCM"));
}


TEST_CASE_METHOD(RomanValidatorTestsFixture, "D, L, and V can each only appear once in roman", "[validator]") {
    CHECK_FALSE(validator.is_valid("DD"));
    CHECK_FALSE(validator.is_valid("LL"));
    CHECK_FALSE(validator.is_valid("VV"));
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "Empty string is always valid", "[validator]") {
    REQUIRE(validator.is_valid(""));
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "MDCLXVI and MCMXC are valid", "[validator]") {
    CHECK(validator.is_valid("MDCLXVI"));
    CHECK(validator.is_valid("MCMXC"));
}


TEST_CASE_METHOD(RomanValidatorTestsFixture, "I can be placed before V and X but not L, C, D or M", "[validator]") {
    CHECK(validator.is_valid("IV"));
    CHECK(validator.is_valid("IX"));
    CHECK_FALSE(validator.is_valid("IL"));
    CHECK_FALSE(validator.is_valid("IC"));
    CHECK_FALSE(validator.is_valid("ID"));
    CHECK_FALSE(validator.is_valid("IM"));
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "X can be placed before L and C but not D or M", "[validator]") {
    CHECK(validator.is_valid("XL"));
    CHECK(validator.is_valid("XC"));
    CHECK_FALSE(validator.is_valid("XD"));
    CHECK_FALSE(validator.is_valid("XM"));
}

TEST_CASE_METHOD(RomanValidatorTestsFixture, "C can be placed before D and M", "[validator]") {
    CHECK(validator.is_valid("CD"));
    CHECK(validator.is_valid("CM"));
}


} //namespace
