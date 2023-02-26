#ifndef _FIRSTCOMMANDUSERCONVERTER_H_
#define _FIRSTCOMMANDUSERCONVERTER_H_
#include "IUserCommandConverter.h"

class FirstCommandUserConverter : public IUserCommandConverter
{
public:
    FirstCommandUserConverter();
    ~FirstCommandUserConverter();
    bool Convert(ICommand *command, uint8_t *commandBuffer, char* userBuffer);

};
#endif // _FIRSTCOMMANDUSERCONVERTER_H_