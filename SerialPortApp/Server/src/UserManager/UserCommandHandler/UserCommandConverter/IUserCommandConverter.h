#ifndef _IUSERCOMMANDCONVERTER_H_
#define _IUSERCOMMANDCONVERTER_H_
#include "Commands/ICommand.h"
class IUserCommandConverter
{
public:
    ~IUserCommandConverter() { }
    virtual bool Convert(ICommand *command, uint8_t *commandBuffer, char* userBuffer) = 0;
};
#endif // _IUSERCOMMANDCONVERTER_H_