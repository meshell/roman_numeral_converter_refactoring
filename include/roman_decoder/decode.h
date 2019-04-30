#ifndef DECODE_H_
#define DECODE_H_

#include "decoder_interface.h"
#include "roman_validator/validator.h"
#include <string>

namespace roman_numerals {

class RomanDecoder: public IDecoder, private RomanNumberValidator {
public:
    virtual ~RomanDecoder() = default;
    unsigned int decode(std::string const & roman);
};


} // namespace roman_numerals

#endif //DECODE_H_
