#ifndef ENCODE_H_
#define ENCODE_H_

#include "encoder_interface.h"
#include <string>

namespace roman_numerals {

class RomanEncoder: public IEncoder{
public:
    std::string encode(unsigned int arabic);
};

} // namespace roman_numerals

#endif //ENCODE_H_
