#ifndef _SERVERCOMMANDRECEIVER_H_
#define _SERVERCOMMANDRECEIVER_H_
#include "ICommandReceiver.h"
#include "Constants.h"
#include "ServerConstants.h"
class ServerCommandReceiver : public ICommandReceiver
{
public:
    ServerCommandReceiver();
    bool Read(uint8_t *buffer);

private:
    uint8_t m_Commands[ServerConstants::MAX_MESSAGE_IN_FILE][Common::Constants::MAX_COMMAND_LENGTH];
    uint32_t m_Length;
    uint32_t m_CurrentIndex;

private:
    void LogBufferToConsole(uint8_t *buffer);

};
#endif //_SERVERCOMMANDRECEIVER_H_