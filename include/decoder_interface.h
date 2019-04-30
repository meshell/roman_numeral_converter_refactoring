#ifndef IDECODER_H_
#define IDECODER_H_

#include <string>

class IDecoder {
public:
    virtual uint32_t decode(const std::string&) = 0;
    virtual ~IDecoder() = default;
};

#endif //IDECODER_H_
