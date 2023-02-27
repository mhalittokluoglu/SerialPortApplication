#include "FirstCommandProcessor.h"
#include "Commands/FirstCommand.h"
#include "Commands/SecondCommand.h"
#include "ClientManager/ClientUtils/ClientUtils.h"
#include <cstdio>

FirstCommandProcessor::FirstCommandProcessor() { }

FirstCommandProcessor::~FirstCommandProcessor() { }

void FirstCommandProcessor::Process(ICommand *command)
{
    FirstCommand *firstCommand = static_cast<FirstCommand*>(command);
    bool bInvalidCrc = false;

    uint16_t crc = firstCommand->CalculateCRC();
    uint16_t receivedCrc = firstCommand->m_Header.m_Crc;
    if (crc != receivedCrc)
        bInvalidCrc = true;

    printf("Command Type: Command1:\n");
    firstCommand->Log();
    if (bInvalidCrc)
    {
        printf("  CRC IS INVALID, received: 0x%04X, calculated: 0x%04X\n", receivedCrc, crc);
        ClientUtils::SendInvalidRequestCommand(EnumInvalidCause::MESSAGE_WITH_CRC_ERROR);
    }
    else
    {
        printf("  CRC is VALID\n");
        SecondCommand secondCommand;
        ReverseDataA(firstCommand->m_A, secondCommand.m_A);
        secondCommand.m_B = firstCommand->m_B * 2;
        secondCommand.m_Header.m_Crc = secondCommand.CalculateCRC();

        if (ClientUtils::SendCommand(&secondCommand))
        {
            printf("Command Type: Command 2:\n");
            secondCommand.Log();
        }
    }

}

void FirstCommandProcessor::ReverseDataA(const DataA &incomingDataA, DataA &outDataA)
{
    outDataA.m_SingleError  = (EnumError)!(incomingDataA.m_SingleError);
    outDataA.m_MessageError = (EnumError)!(incomingDataA.m_MessageError);
    outDataA.m_SignalStateA = (EnumSignalState)!(incomingDataA.m_SignalStateA);
    outDataA.m_SignalStateB = (EnumSignalState)!(incomingDataA.m_SignalStateB);
    outDataA.m_SignalStateC = (EnumSignalState)!(incomingDataA.m_SignalStateC);
    outDataA.m_DoubleError  = (EnumError)!(incomingDataA.m_DoubleError);

    uint8_t loadState = incomingDataA.m_LoadState;
    loadState = ~loadState;
    loadState = loadState & 0b00000011;
    outDataA.m_LoadState    = (EnumLoadState)loadState;
}

