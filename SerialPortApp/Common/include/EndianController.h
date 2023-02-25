#ifndef _ENDIANCONTROLLER_H_
#define _ENDIANCONTROLLER_H_
class EndianController
{
public:
    bool IsBigEndian();
    static EndianController* Instance();
    void ConvertFromLittleToBigEndian(char *inputBuffer, char *outputBuffer, int length);
private:
    static EndianController *s_Instance;
    bool m_IsBigEndian;
    EndianController();
};
#endif // _ENDIANCONTROLLER_H_