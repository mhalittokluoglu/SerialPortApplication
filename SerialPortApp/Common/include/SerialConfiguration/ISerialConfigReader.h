#ifndef _ISERIALCONFIGREADER_H_
#define _ISERIALCONFIGREADER_H_
#include "SerialConfiguration.h"
class ISerialConfigReader
{
public:
    virtual ~ISerialConfigReader() { }
    virtual bool ReadConfiguration(const char *configurationFilePath, SerialConfiguration &configuration) = 0;
};
#endif // _ISERIALCONFIGREADER_H_