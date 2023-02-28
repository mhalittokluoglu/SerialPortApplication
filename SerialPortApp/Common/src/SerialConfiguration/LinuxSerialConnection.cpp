#include "LinuxSerialConnection.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "termios.h"

using namespace Common;

int TermiousMap[] = {
                        B50,
                        B75,
                        B110,
                        B134,
                        B150,
                        B200,
                        B300,
                        B600,
                        B1200,
                        B1800,
                        B2400,
                        B4800,
                        B9600,
                        B19200,
                        B38400
};

int DataBitMap[] = {
                        CS5,
                        CS6,
                        CS7,
                        CS8
};

LinuxSerialConnection::LinuxSerialConnection() {}

LinuxSerialConnection::~LinuxSerialConnection()
{
    close(m_SerialPortFileDescriptor);
}

bool LinuxSerialConnection::Initialize(const SerialConfiguration &configuration, int vTimeInDesiSecond, int vMinInDesiSecond)
{
    m_SerialPortFileDescriptor = open(configuration.DEVICE, O_RDWR);
    if (m_SerialPortFileDescriptor < 0)
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_COMMON, "Unable to Create Serial Connection!");
#endif
        return false;
    }

    m_Options.c_cflag = TermiousMap[configuration.BAUD_RATE] |
        DataBitMap[configuration.DATA_BIT] | 
        CLOCAL | CREAD;
    
    if (configuration.PARITY == PARITY_DISABLED)
        m_Options.c_cflag &= ~PARENB;
    else if(configuration.PARITY == PARITY_ENABLED)
        m_Options.c_cflag |= PARENB;

    if (configuration.STOP_BIT == ONE_STOP_BIT)
        m_Options.c_cflag &= ~CSTOPB;
    else if (configuration.STOP_BIT == TWO_STOP_BIT)
        m_Options.c_cflag |= CSTOPB;

    m_Options.c_iflag = IGNPAR;
    m_Options.c_oflag = 0;
    m_Options.c_lflag = 0;
    m_Options.c_cc[VTIME] = vTimeInDesiSecond;
    m_Options.c_cc[VMIN] = vMinInDesiSecond;

    tcflush(m_SerialPortFileDescriptor, TCIFLUSH);
    tcsetattr(m_SerialPortFileDescriptor, TCSANOW, &m_Options);
    return true;

}

bool LinuxSerialConnection::Send(char *buffer, int len)
{
    bool bResult = false;
    len = write(m_SerialPortFileDescriptor, buffer, len);
    if (len > 0)
        bResult = true;
    return bResult;
}

bool LinuxSerialConnection::Receive(char *buffer, int &len)
{
    bool bResult = false;
    len = read(m_SerialPortFileDescriptor, buffer, len);
    if (len > 0)
        bResult = true;
    return bResult;
}
