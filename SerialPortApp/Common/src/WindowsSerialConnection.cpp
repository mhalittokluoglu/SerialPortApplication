#include "WindowsSerialConnection.h"

static const int BaudRateMap[] = {
    50,
    75,
    110,
    134,
    150,
    200,
    300,
    600,
    1200,
    1800,
    2400,
    4800,
    9600,
    19200,
    38400,
};

static const int ByteSizeMap[] = {
    5,
    6,
    7,
    8
};

static const int StopBitMap[] = {
    1,
    2
};

static const int ParityMap[] = {
    0,
    1
};

WindowsSerialConnection::WindowsSerialConnection() { }

WindowsSerialConnection::~WindowsSerialConnection()
{
    CloseHandle(m_SerialHandle);
}

bool WindowsSerialConnection::Initialize(const SerialConfiguration &configuration, int vTime, int vMin)
{
    bool bResult = true;
    m_SerialHandle = CreateFile((LPCSTR)configuration.DEVICE, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (m_SerialHandle == INVALID_HANDLE_VALUE)
    {
        bResult = false;
    }

    DCB serialParams = { 0 };
    if (!GetCommState(m_SerialHandle, &serialParams))
    {
        bResult = false;
    }

    serialParams.DCBlength = sizeof(serialParams);
    serialParams.BaudRate =  BaudRateMap[configuration.BAUD_RATE];
    serialParams.ByteSize = ByteSizeMap[configuration.DATA_BIT];
    serialParams.StopBits = StopBitMap[configuration.STOP_BIT];
    serialParams.Parity = ParityMap[configuration.PARITY];
    SetCommState(m_SerialHandle, &serialParams);

    COMMTIMEOUTS timeout = { 0 };
    timeout.ReadIntervalTimeout = vMin;
    timeout.ReadTotalTimeoutConstant = vTime;
    timeout.ReadTotalTimeoutMultiplier = 1;
    timeout.WriteTotalTimeoutConstant = 0;
    timeout.WriteTotalTimeoutMultiplier = 1;
    SetCommTimeouts(m_SerialHandle, &timeout);
    return bResult;
}

bool WindowsSerialConnection::Send(char *buffer, int len)
{
    bool bResult = false;
    LPDWORD lengthOfWrittenBytes = 0;
    if(WriteFile(m_SerialHandle, buffer, len, lengthOfWrittenBytes, NULL))
    {
        bResult = true;
    }
    return bResult;
}

bool WindowsSerialConnection::Receive(char *buffer, int &len)
{
    bool bResult = false;
    DWORD lengthOfReadedBytes;
    if(ReadFile(m_SerialHandle, buffer, len, &lengthOfReadedBytes, NULL))
    {
        if (lengthOfReadedBytes > 0)
            bResult = true;
    }
    return bResult;
}
