#include "roman_encoder/encode.h"

#include <array>
#include <utility>

using namespace std::string_literals;

namespace roman_numerals {

std::string RomanEncoder::encode(unsigned int arabic) {
    
    typedef struct {
        unsigned int arabic;
        std::string roman;
    } ArrayElemT;
    
    const size_t size_of_array = 13;
    const ArrayElemT to_roman_mapping[size_of_array] =
    {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
     };

    std::string roman = "";
    
    ArrayElemT const* ptr = to_roman_mapping;
    for (unsigned i = 0; i < size_of_array; ++i, ptr++) {
        while (arabic >= ptr->arabic) {
            roman += ptr->roman;
            arabic -= ptr->arabic;
        }
    }

    return roman;
}

} // namespace roman_numerals
