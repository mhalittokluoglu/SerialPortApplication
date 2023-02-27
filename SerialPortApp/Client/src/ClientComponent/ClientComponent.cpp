#include "ClientComponent.h"
#include "SerialConfiguration/SerialConnectionFactory.h"
#include "SerialConfiguration/SerialConfigReader.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED


ClientComponent::ClientComponent()
{
    ISerialConnection* serialConnection = SerialConnectionFactory::CreateSerialConnection();
    SerialConfiguration serialConfiguration;
    SerialConfigReader reader;
    if (!reader.ReadConfiguration("Configuration/PortConfigurationClient.csv", serialConfiguration))
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Configuration is not valid!");
#endif // LOG_ENABLED
    }

    if (!serialConnection->Initialize(serialConfiguration, 0,0))
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_SERVER, "Serial Port Initilization Failed!");
#endif // LOG_ENABLED
    }
    m_ClientManager = new ClientManager(serialConnection);

}

ClientComponent::~ClientComponent() { }

void ClientComponent::RunApplication()
{
    m_ClientManager->Run();
}