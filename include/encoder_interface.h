#ifndef IENCODER_H_
#define IENCODER_H_

#include <string>

class IEncoder{
public:
    virtual std::string encode(unsigned int ) = 0;
    virtual ~IEncoder() {};

};

#endif //IENCODER_H_
