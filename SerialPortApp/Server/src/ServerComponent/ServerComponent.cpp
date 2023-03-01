#include "ServerComponent.h"
#include "UserManager/UserManager.h"
#include "SerialConfiguration/SerialConnectionFactory.h"
#include "SerialConfiguration/SerialConfigReader.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif


ServerComponent::ServerComponent()
{

    Common::ISerialConnection* serialConnection = Common::SerialConnectionFactory::CreateSerialConnection();
    Common::SerialConfiguration serialConfiguration;
    Common::SerialConfigReader reader;
    if (!reader.ReadConfiguration("Configuration/PortConfigurationServer.csv", serialConfiguration))
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Configuration is not valid!");
#endif
    }

    if (!serialConnection->Initialize(serialConfiguration, 10,0))
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_SERVER, "Serial Port Initilization Failed!");
#endif
    }

    m_State = NORMAL;
    m_UserManager = new UserManager(&m_State, serialConnection);
    m_ServerManager = new ServerManager(serialConnection);

}

ServerComponent::~ServerComponent() { }

void ServerComponent::RunApplication()
{
    m_UserManager->Run();
    m_ServerManager->Run();
}