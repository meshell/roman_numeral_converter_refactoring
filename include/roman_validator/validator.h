#ifndef ROMAN_NUMERAL_VALIDATER_H_
#define ROMAN_NUMERAL_VALIDATER_H_

#include "validator_interface.h"
#include <string>

namespace roman_numerals {
class RomanNumberValidator: public IValidator {
public:
    bool is_valid(const std::string& roman);
};



} // namespace roman_numerals

#endif //ROMAN_NUMERAL_VALIDATER_H_
