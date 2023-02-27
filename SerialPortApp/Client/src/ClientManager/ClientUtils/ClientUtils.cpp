#include "ClientUtils.h"
#include "Commands/InvalidRequestCommand.h"
#include "Commands/ByteStream.h"
#include <cstddef>
#include <cstdio>

ISerialConnection *ClientUtils::s_SerialConnection = NULL;

void ClientUtils::Initialize(ISerialConnection *serialConnection)
{
    s_SerialConnection = serialConnection;
}

bool ClientUtils::SendInvalidRequestCommand(EnumInvalidCause cause)
{
    InvalidRequestCommand invalidRequestCommand;
    invalidRequestCommand.m_InvalidCause = cause;
    invalidRequestCommand.m_Header.m_Crc = invalidRequestCommand.CalculateCRC();
    if (SendCommand(&invalidRequestCommand))
    {
        printf("  Command Type: InvalidRequestCommand\n");
        invalidRequestCommand.Log();
        printf("\n");
        return true;
    }
    return false;
}

bool ClientUtils::SendCommand(ICommand *command)
{
    uint8_t buffer[ByteStream::BUFFER_LENGTH] = { 0 };
    uint32_t length = sizeof(buffer);
    ByteStream byteStream(buffer);
    command->Serialize(byteStream, length);
    if (s_SerialConnection->Send((char*)buffer, length))
    {
        printf("Message Sent: ");
        byteStream.Log();
        return true;
    }
    return false;
}
