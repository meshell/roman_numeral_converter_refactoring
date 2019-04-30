#ifndef DECODE_H_
#define DECODE_H_

#include "decoder_interface.h"
#include "validator_interface.h"
#include <string>
#include <memory>

namespace roman_numerals {

class RomanDecoder final: public IDecoder {
public:
    RomanDecoder(std::unique_ptr<IValidator> validator)
            : m_validator{std::move(validator)}
    {

    }
    virtual ~RomanDecoder() = default;
    uint32_t decode(const std::string &roman) final;
private:
    std::unique_ptr<IValidator> m_validator;
};


} // namespace roman_numerals

#endif //DECODE_H_
