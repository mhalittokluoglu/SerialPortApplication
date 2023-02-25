#ifndef _BASECOMMAND_H_
#define _BASECOMMAND_H_
#include "ICommand.h"
class BaseCommand : public ICommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() { }
    virtual bool Serialize(ByteStream &byteStream);
    virtual bool Deserialize(ByteStream &byteStream);

// protected:
    uint8_t m_Heading;
    uint8_t m_CommandLength;
    uint8_t m_CommandNo;
    uint16_t m_Crc;

};
#endif // _BASECOMMAND_H_