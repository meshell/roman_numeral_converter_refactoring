#include "roman_decoder/decode.h"
#include "roman_validator/validator.h"
#include <catch.hpp>

namespace {

    using namespace roman_numerals;

class RomanDecoderTestsFixture {
protected:
    RomanDecoder<RomanNumberValidator> decoder{};
};

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode I - III to 1 - 3", "[decoder]") {
    REQUIRE(decoder.decode("I") == 1);
    REQUIRE(decoder.decode("II") == 2);
    REQUIRE(decoder.decode("III") == 3);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode X, XX, XXX to 10, 20, 30", "[decoder]") {
    REQUIRE(decoder.decode("X") == 10);
    REQUIRE(decoder.decode("XX") == 20);
    REQUIRE(decoder.decode("XXX") == 30);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode XIII to 13, XXII to 22 and XXXI to 31", "[decoder]") {
    REQUIRE(decoder.decode("XIII") == 13);
    REQUIRE(decoder.decode("XXII") == 22);
    REQUIRE(decoder.decode("XXXI") == 31);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode C, CC and CCC to 100, 200, 300", "[decoder]") {
    REQUIRE(decoder.decode("C") == 100);
    REQUIRE(decoder.decode("CC") == 200);
    REQUIRE(decoder.decode("CCC") == 300);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode M, MM, MMM and MMMM to 000, 2000, 3000 and 4000", "[decoder]") {
    REQUIRE(decoder.decode("M") == 1000);
    REQUIRE(decoder.decode("MM") == 2000);
    REQUIRE(decoder.decode("MMM") == 3000);
    REQUIRE(decoder.decode("MMMM") == 4000);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode V as 5", "[decoder]") {
    REQUIRE(decoder.decode("V") == 5);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode L as 50", "[decoder]") {
    REQUIRE(decoder.decode("L") == 50);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode D as 500", "[decoder]") {
    REQUIRE(decoder.decode("D") == 500);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode IV as 4", "[decoder]") {
    REQUIRE(decoder.decode("IV") == 4);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode IX as 9", "[decoder]") {
    REQUIRE(decoder.decode("IX") == 9);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode XL as 40", "[decoder]") {
    REQUIRE(decoder.decode("XL") == 40);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode XC as 90", "[decoder]") {
    REQUIRE(decoder.decode("XC") == 90);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode CD as 400", "[decoder]") {
    REQUIRE(decoder.decode("CD") == 400);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode CM as 900", "[decoder]") {
    REQUIRE(decoder.decode("CM") == 900);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode MDCLXVI as 1666", "[decoder]") {
    REQUIRE(decoder.decode("MDCLXVI") == 1666);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder can decode MCMXC as 1990", "[decoder]") {
    REQUIRE(decoder.decode("MCMXC") == 1990);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder decodes empty string to 0", "[decoder]") {
    REQUIRE(decoder.decode("") == 0);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "A roman numbers decoder throws invalid_argument exception for invalid string", "[decoder]") {
    REQUIRE_THROWS_AS(decoder.decode("ABC"), std::invalid_argument);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "M, C, and X cannot be equalled or exceeded by smaller denominations.", "[decoder]") {
    CHECK_THROWS_AS(decoder.decode("IIIIIIIIII"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("CCCCCCCCCC"), std::invalid_argument);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "D, L, and V can each only appear once", "[decoder]") {
    CHECK_THROWS_AS(decoder.decode("VV"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("VIV"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("DCD"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("CDD"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("XLL"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("LXL"), std::invalid_argument);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "I can only be placed before V and X.", "[decoder]") {
    CHECK_THROWS_AS(decoder.decode("IL"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("IC"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("ID"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("IM"), std::invalid_argument);
}

TEST_CASE_METHOD(RomanDecoderTestsFixture, "X can only be placed before L and C", "[decoder]") {
    CHECK_THROWS_AS(decoder.decode("XD"), std::invalid_argument);
    CHECK_THROWS_AS(decoder.decode("XM"), std::invalid_argument);
}

} //namespace
