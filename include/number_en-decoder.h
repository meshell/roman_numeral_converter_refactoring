#ifndef NUMBER_ENCODER_DECODER_H_
#define NUMBER_ENCODER_DECODER_H_

#include <string>


template<class EncoderT, class DecoderT>
struct NumberEncoderDecoder: EncoderT, DecoderT
{
};

#endif //NUMBER_ENCODER_DECODER_H_
