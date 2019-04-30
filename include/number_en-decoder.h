#ifndef NUMBER_ENCODER_DECODER_H_
#define NUMBER_ENCODER_DECODER_H_

#include <string>


template<class T, class S>
struct NumberEncoderDecoder
{
    uint32_t decode(std::string const& roman) const {
        static S const decoder{};
        return decoder.decode(roman);
    }

    std::string encode(uint32_t arabic) const {
        static T const encoder;
        return encoder.encode(arabic);
    }
};

#endif //NUMBER_ENCODER_DECODER_H_