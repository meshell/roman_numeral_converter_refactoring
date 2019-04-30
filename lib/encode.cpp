#include "roman_encoder/encode.h"

#include <array>
#include <utility>

using namespace std::string_literals;

namespace roman_numerals {

std::string RomanEncoder::encode(uint32_t arabic) const {
    std::array<std::pair<uint32_t, char const *>, 13> const to_roman_mapping =
            {{
                     std::make_pair(1000, "M"),
                     std::make_pair(900, "CM"),
                     std::make_pair(500, "D"),
                     std::make_pair(400, "CD"),
                     std::make_pair(100, "C"),
                     std::make_pair(90, "XC"),
                     std::make_pair(50, "L"),
                     std::make_pair(40, "XL"),
                     std::make_pair(10, "X"),
                     std::make_pair(9, "IX"),
                     std::make_pair(5, "V"),
                     std::make_pair(4, "IV"),
                     std::make_pair(1, "I")
             }};

    auto roman = ""s;
    for (auto const & kvp : to_roman_mapping) {
        while (arabic >= kvp.first) {
            roman += kvp.second;
            arabic -= kvp.first;
        }
    }

    return roman;
}

} // namespace roman_numerals
