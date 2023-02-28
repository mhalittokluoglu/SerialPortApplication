#include "ClientUtils.h"
#include "Commands/InvalidRequestCommand.h"
#include "Constants.h"
#include <cstddef>
#include <cstdio>

using namespace Common;

IConnection *ClientUtils::s_Connection = NULL;

void ClientUtils::Initialize(IConnection *connection)
{
    s_Connection = connection;
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
        return true;
    }
    return false;
}

bool ClientUtils::SendCommand(ISerializableCommand *command)
{
    uint8_t buffer[Constants::MAX_COMMAND_LENGTH] = { 0 };
    uint32_t length = sizeof(buffer);
    ByteStream byteStream(buffer);
    command->Serialize(byteStream, length);
    if (s_Connection->Send((char*)buffer, length))
    {
        printf("Message Sent: ");
        byteStream.Log();
        return true;
    }
    return false;
}
