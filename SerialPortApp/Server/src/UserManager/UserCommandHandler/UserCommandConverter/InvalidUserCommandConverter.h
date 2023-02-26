#ifndef _INVALIDUSERCOMMANDCONVERTER_H_
#define _INVALIDUSERCOMMANDCONVERTER_H_
#include "IUserCommandConverter.h"

class InvalidUserCommandConverter : public IUserCommandConverter
{
public:
    InvalidUserCommandConverter();
    ~InvalidUserCommandConverter();
    virtual bool Convert(ICommand *command, uint8_t *commandBuffer, char* userBuffer);

};
#endif // _INVALIDUSERCOMMANDCONVERTER_H_