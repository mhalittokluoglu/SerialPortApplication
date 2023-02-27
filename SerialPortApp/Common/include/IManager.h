#ifndef _IMANAGER_H_
#define _IMANAGER_H_
class IManager
{
public:
    virtual ~IManager() { }
    virtual void Run() = 0;
};
#endif // _IMANAGER_H_