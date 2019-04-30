#include "roman_encoder/encode.h"
#include <catch.hpp>

namespace {


using Catch::Matchers::Equals;

class RomanEncoderTestsFixture {
protected:
    roman_numerals::RomanEncoder encoder{};
};


TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode numbers 1 to 3 as I, II, III", "[encoder]") {
    REQUIRE_THAT(encoder.encode(1), Equals("I"));
    REQUIRE_THAT(encoder.encode(2), Equals("II"));
    REQUIRE_THAT(encoder.encode(3), Equals("III"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode numbers 10, 20 and 30 as X, XX, XXX", "[encoder]") {
    REQUIRE_THAT(encoder.encode(10), Equals("X"));
    REQUIRE_THAT(encoder.encode(20), Equals("XX"));
    REQUIRE_THAT(encoder.encode(30), Equals("XXX"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode numbers 100, 200 and 300 as C, CC, CCC", "[encoder]") {
    REQUIRE_THAT(encoder.encode(100), Equals("C"));
    REQUIRE_THAT(encoder.encode(200), Equals("CC"));
    REQUIRE_THAT(encoder.encode(300), Equals("CCC"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode numbers 1000, 2000, 3000 and 4000 as M, MM, MMM, MMMM", "[encoder]") {
    REQUIRE_THAT(encoder.encode(1000), Equals("M"));
    REQUIRE_THAT(encoder.encode(2000), Equals("MM"));
    REQUIRE_THAT(encoder.encode(3000), Equals("MMM"));
    REQUIRE_THAT(encoder.encode(4000), Equals("MMMM"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 5 as V", "[encoder]") {
    REQUIRE_THAT(encoder.encode(5), Equals("V"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 50 as L", "[encoder]") {
    REQUIRE_THAT(encoder.encode(50), Equals("L"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 500 as D", "[encoder]") {
    REQUIRE_THAT(encoder.encode(500), Equals("D"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 4 as IV", "[encoder]") {
    REQUIRE_THAT(encoder.encode(4), Equals("IV"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 9 as IX", "[encoder]") {
    REQUIRE_THAT(encoder.encode(9), Equals("IX"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 40 as XL", "[encoder]") {
    REQUIRE_THAT(encoder.encode(40), Equals("XL"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 90 as XC", "[encoder]") {
    REQUIRE_THAT(encoder.encode(90), Equals("XC"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 400 as CD", "[encoder]") {
    REQUIRE_THAT(encoder.encode(400), Equals("CD"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 90 as CM", "[encoder]") {
    REQUIRE_THAT(encoder.encode(900), Equals("CM"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 1666 as MDCLXVI", "[encoder]") {
    REQUIRE_THAT(encoder.encode(1666), Equals("MDCLXVI"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 1990 as MCMXC", "[encoder]") {
    REQUIRE_THAT(encoder.encode(1990), Equals("MCMXC"));
}

TEST_CASE_METHOD(RomanEncoderTestsFixture, "A roman numbers encoder can encode 0 as nothing", "[encoder]") {
    REQUIRE_THAT(encoder.encode(0), Equals(""));
}

} //namespace
