#ifndef ENCODE_H_
#define ENCODE_H_

#include <string>

namespace roman_numerals {

struct RomanEncoder{
    std::string encode(uint32_t arabic) const;
};

} // namespace roman_numerals

#endif //ENCODE_H_
