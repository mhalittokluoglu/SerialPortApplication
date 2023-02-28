#ifndef _IMANAGER_H_
#define _IMANAGER_H_
namespace Common
{
    class IManager
    {
    public:
        virtual ~IManager() {}
        virtual void Run() = 0;
    };
} // Common

#endif // _IMANAGER_H_