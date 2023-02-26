#include "ServerComponent.h"
#include "UserManager/UserManager.h"
#include "SerialConfiguration/SerialConnectionFactory.h"
#include "SerialConfiguration/SerialConfigReader.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif



ServerComponent::ServerComponent()
{

    ISerialConnection* serialConnection = SerialConnectionFactory::CreateSerialConnection();
    SerialConfiguration serialConfiguration;
    SerialConfigReader reader;
    if (!reader.ReadConfiguration("Configuration/PortConfigurationServer.csv", serialConfiguration))
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Configuration is not valid!");
#endif
    }

    if (!serialConnection->Initialize(serialConfiguration, 0,0))
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_SERVER, "Serial Port Initilization Failed!");
#endif
    }

    m_State = NORMAL;
    m_UserManager = new UserManager(&m_State, serialConnection);

}

ServerComponent::~ServerComponent() { }

void ServerComponent::RunApplication()
{
    m_UserManager->Run();
}