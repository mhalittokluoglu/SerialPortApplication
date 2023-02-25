#ifndef _SERIALCONFIGURATION_H_
#define _SERIALCONFIGURATION_H_
#include <inttypes.h>

enum EnumBaudRate
{
    BAUD_RATE_50,
    BAUD_RATE_75,
    BAUD_RATE_110,
    BAUD_RATE_134,
    BAUD_RATE_150,
    BAUD_RATE_200,
    BAUD_RATE_300,
    BAUD_RATE_600,
    BAUD_RATE_1200,
    BAUD_RATE_1800,
    BAUD_RATE_2400,
    BAUD_RATE_4800,
    BAUD_RATE_9600,
    BAUD_RATE_19200,
    BAUD_RATE_38400,
    MAX_BAUD_RATE
};

enum EnumDataBit
{
    DATA_BIT_5,
    DATA_BIT_6,
    DATA_BIT_7,
    DATA_BIT_8,
    MAX_DATA_BIT
};

enum EnumParity
{
    PARITY_ENABLED,
    PARITY_DISABLED,
    MAX_PARITY
};

enum EnumStopBit
{
    ONE_STOP_BIT,
    TWO_STOP_BIT,
    MAX_STOP_BIT
};

struct SerialConfiguration
{
    static const int MAX_DEVICE_CHAR_LENGTH = 256;
    char DEVICE[MAX_DEVICE_CHAR_LENGTH];
    EnumBaudRate BAUD_RATE;
    EnumDataBit DATA_BIT;
    EnumParity PARITY;
    EnumStopBit STOP_BIT;
    SerialConfiguration(EnumBaudRate baudRate = MAX_BAUD_RATE,
                        EnumDataBit databit = MAX_DATA_BIT,
                        EnumParity parity = MAX_PARITY,
                        EnumStopBit stopBit =  MAX_STOP_BIT):
        DEVICE {'N', 'U', 'L', 'L', '\0'},
        BAUD_RATE { baudRate },
        DATA_BIT { databit },
        PARITY { parity },
        STOP_BIT { stopBit }
        {
        }

    void LogInformation()
    {
        
    }
};
#endif // _SERIALCONFIGURATION_H_