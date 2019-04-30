#include "roman_validator/validator.h"

#include <map>
#include <algorithm>
#include <array>

namespace roman_numerals {

bool RomanNumberValidator::is_valid(const std::string& roman) {
    const std::map<char, uint32_t> to_arabic_mapping =
    {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
    };

    const std::array<char, 3> five_x_digits = { {'D', 'L', 'V'} };

    if (roman.empty()) {
        return true;
    }
    // Check that the digits V, L and D are not repeated
    for (const auto& digit : five_x_digits) {
        if (std::count(roman.begin(), roman.end(), digit) > 1) {
            return false;
        }
    }
    // check all symbols are valid
    for (const auto& numeral : roman) {
        if (to_arabic_mapping.count(numeral) == 0) {
            return false;
        };
    }
    // check for equal consecutive symbols
    char prev_numeral = '\0';
    auto count_consecutive_equals = 1u;
    for (const auto& numeral : roman) {
        if (numeral == prev_numeral) {
            ++count_consecutive_equals;
            if (count_consecutive_equals == 10) {
                return false;
            }
        }
        else {
            count_consecutive_equals = 1;
        }
        prev_numeral = numeral;
    }
    // check sum is smaller
    auto prev = 0u;
    auto roman_reverse = roman;
    auto arabic = 0u;
    std::reverse(roman_reverse.begin(), roman_reverse.end());
    auto next_decimal = to_arabic_mapping.at(roman_reverse.at(0)) * 10;
    for (const auto& numeral : roman_reverse) {
        const auto inc = to_arabic_mapping.at(numeral);
        if (inc >= next_decimal) {
            arabic = 0;
            next_decimal = inc % next_decimal == 0 ? inc * 10 : inc + inc;
        }
        arabic += inc < prev ? -inc : inc;
        if (arabic >= next_decimal) {
            return false;
        }
        prev = inc;
    }
    prev = 0u;
    for (const auto& numeral : roman_reverse) {
        const auto inc = to_arabic_mapping.at(numeral);
        if ((inc < prev) && ((prev - inc) > (10 * inc))) {
            return false;
        }
        prev = inc;
    }
    return true;
}

} // namespace roman_numerals
