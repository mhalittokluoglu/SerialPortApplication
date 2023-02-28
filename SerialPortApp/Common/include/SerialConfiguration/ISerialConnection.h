#ifndef _ISERIALCONNECTION_H_
#define _ISERIALCONNECTION_H_
#include "SerialConfiguration.h"
#include "IConnection.h"

namespace Common
{
    class ISerialConnection : public IConnection
    {
    public:
        virtual ~ISerialConnection() {}
        virtual bool Initialize(const SerialConfiguration &configuration, int vTimeInDesiSecond = 0, int vMinInDesiSecond = 0) = 0;
    };
} // Common
#endif // _ISERIALCONNECTION_H_