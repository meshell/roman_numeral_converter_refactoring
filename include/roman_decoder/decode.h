#ifndef DECODE_H_
#define DECODE_H_

#include <string>
#include <memory>
#include <map>
#include <ciso646>
#include <algorithm>

namespace roman_numerals {

template<class Validator>
struct RomanDecoder: Validator {
    uint32_t decode(std::string const & roman) const {
        std::map<char, int32_t> const to_arabic_mapping =
        {
                {'M', 1000},
                {'D', 500},
                {'C', 100},
                {'L', 50},
                {'X', 10},
                {'V', 5},
                {'I', 1}
        };

        auto arabic = 0;
        auto prev = 0;
        if (not this->is_valid(roman)) {
            throw std::invalid_argument{ "Invalid string provided" };
        }

        std::for_each(roman.crbegin(), roman.crend(), [&](auto const & ch) {
            auto const inc = to_arabic_mapping.at(ch);
            arabic += inc < prev ? -inc : inc;
            prev = inc;
            });

        return arabic;
    }
};


} // namespace roman_numerals

#endif //DECODE_H_
