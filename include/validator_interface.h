#ifndef IVALIDATOR_H_
#define IVALIDATOR_H_

#include <string>

class IValidator{
public:
    virtual bool is_valid(const std::string&) = 0;
    virtual ~IValidator() = default;

};

#endif //IVALIDATOR_H_
