#ifndef IENCODER_H_
#define IENCODER_H_

#include <string>

class IEncoder{
public:
    virtual std::string encode(uint32_t ) = 0;
    virtual ~IEncoder() = default;

};

#endif //IENCODER_H_
