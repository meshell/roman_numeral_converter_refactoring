#ifndef ENCODE_H_
#define ENCODE_H_

#include "encoder_interface.h"
#include <string>

namespace roman_numerals {

class RomanEncoder final: public IEncoder{
public:
    std::string encode(uint32_t arabic) final;
};

} // namespace roman_numerals

#endif //ENCODE_H_
