#ifndef IDECODER_H_
#define IDECODER_H_

#include <string>

class IDecoder {
public:
    virtual unsigned int decode(std::string const &) = 0;
    virtual ~IDecoder() {};
};

#endif //IDECODER_H_
