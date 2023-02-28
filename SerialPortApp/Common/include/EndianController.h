#ifndef _ENDIANCONTROLLER_H_
#define _ENDIANCONTROLLER_H_

namespace Common
{
    class EndianController
    {
    public:
        bool IsBigEndian();
        static EndianController *Instance();

    private:
        static EndianController *s_Instance;
        bool m_IsBigEndian;
        EndianController();
    };
} // Common

#endif // _ENDIANCONTROLLER_H_