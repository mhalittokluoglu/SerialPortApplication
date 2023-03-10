#include "SerialConfiguration/SerialConfigReaderFactory.h"
#ifdef DEFAULT_CONFIG_READER
#include "SerialConfiguration/SerialConfigReader.h"
#endif // DEFAULT_CONFIG_READER

using namespace Common;

ISerialConfigReader* SerialConfigReaderFactory::CreateSerialConfigReader()
{
#ifdef DEFAULT_CONFIG_READER
    return new SerialConfigReader();
#endif // DEFAULT_CONFIG_READER
}