#ifndef _SERIALCONFIGREADER_H_
#define _SERIALCONFIGREADER_H_
#include "SerialConfiguration.h"

class SerialConfigReader
{
public:
    SerialConfigReader();
    ~SerialConfigReader();
    bool ReadConfiguration(const char *configurationFilePath, SerialConfiguration &configuration);

private:
    bool ConvertDevice(char *buffer, char *device, int length);
    bool ConvertBaudRate(const char *buffer, EnumBaudRate &baudRate);
    bool ConvertDataBit(const char *buffer, EnumDataBit &dataBit);
    bool ConvertParity(const char *buffer, EnumParity &parity);
    bool ConvertStopBit(const char *buffer, EnumStopBit &stopBit);
    
};
#endif // _SERIALCONFIGREADER_H_