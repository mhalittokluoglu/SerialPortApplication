#ifndef _ICONNECTION_H_
#define _ICONNECTION_H_

namespace Common
{
    class IConnection
    {
    public:
        virtual ~IConnection() {}
        virtual bool Send(char *buffer, int len) = 0;
        virtual bool Receive(char *buffer, int &len) = 0;
    };
} // Common

#endif // _ICONNECTION_H_