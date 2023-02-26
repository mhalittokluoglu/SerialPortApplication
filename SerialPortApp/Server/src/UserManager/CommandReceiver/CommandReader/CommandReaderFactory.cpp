#include "CommandReaderFactory.h"
#include <cstddef>

#ifdef COMMAND_READER_DEFAULT
#include "CommandReader.h"
#endif // COMMAND_READER_DEFAULT

ICommandReader *CommandReaderFactory::CreateCommandReader()
{
    ICommandReader *reader = NULL;

#ifdef COMMAND_READER_DEFAULT
    reader = new CommandReader();
#endif // COMMAND_READER_DEFAULT

    return reader;
}
