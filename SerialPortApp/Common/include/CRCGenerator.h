#ifndef _CRCGENERATOR_H_
#define _CRCGENERATOR_H_
#include <inttypes.h>

namespace Common
{
    class CRCGenerator
    {
    public:
        static uint16_t CalculateCRC16(const void *vPtr, uint32_t length);
    };
} // Common
#endif // _CRCGENERATOR_H_