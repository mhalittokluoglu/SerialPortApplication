#include "Commands/Data/DataA.h"
#include <cstring>

DataA::DataA()
{
    Reset();
}

DataA::~DataA() { }

void DataA::Serialize(uint8_t &data)
{
    memset(&data, 0, sizeof(data));
    data |= m_SingleError << 7;
    data |= m_MessageError << 6;
    data |= m_SignalStateA << 5;
    data |= m_SignalStateB << 4;
    data |= m_SignalStateC << 3;
    data |= m_DoubleError << 2;
    data |= m_LoadState;
}

void DataA::Deserialize(const uint8_t &data)
{
    m_SingleError   = (EnumError)       ((data & 0b10000000) >> 7);
    m_MessageError  = (EnumError)       ((data & 0b01000000) >> 6);
    m_SignalStateA  = (EnumSignalState) ((data & 0b00100000) >> 5);
    m_SignalStateB  = (EnumSignalState) ((data & 0b00010000) >> 4);
    m_SignalStateC  = (EnumSignalState) ((data & 0b00001000) >> 3);
    m_DoubleError   = (EnumError)       ((data & 0b00000100) >> 2);
    m_LoadState     = (EnumLoadState)   (data & 0b00000011);
}

void DataA::Reset()
{
    m_SingleError = NO_ERROR;
    m_MessageError = NO_ERROR;
    m_SignalStateA = LOW;
    m_SignalStateB = LOW;
    m_SignalStateC = LOW;
    m_DoubleError = NO_ERROR;
    m_LoadState = NO_LOAD;
}