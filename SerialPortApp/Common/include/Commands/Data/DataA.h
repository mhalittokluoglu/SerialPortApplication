#ifndef _DATAA_H_
#define _DATAA_H_
#include <inttypes.h>
#include "Commands/DataElements.h"
struct DataA
{
    EnumError m_SingleError;
    EnumError m_MessageError;
    EnumSignalState m_SignalStateA;
    EnumSignalState m_SignalStateB;
    EnumSignalState m_SignalStateC;
    EnumError m_DoubleError;
    EnumLoadState m_LoadState;

    DataA();
    ~DataA();
    void Serialize(uint8_t &data);
    void Deserialize(const uint8_t &data);
    void Reset();
    
};
#endif // _DATAA_H_