#ifndef _ISOCKETCLIENT_H_
#define _ISOCKETCLIENT_H_
class ISocketClient
{
public:
    virtual ~ISocketClient() {}
    virtual void SendData(const char *data, int length) = 0;
};
#endif // _ISOCKETCLIENT_H_