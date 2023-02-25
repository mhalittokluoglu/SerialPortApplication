#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <inttypes.h>

enum EnumComponentType
{
    COMPONENT_SERVER,
    COMPONENT_CLIENT,
    COMPONENT_COMMON,
};

class Logger
{
public:

    /** Log Debug
     * MAX LOG CHAR: 2048
    */
    static void LOG_DEBUG(EnumComponentType componentType, const char* format, ...);

    /** Log Error
     * MAX LOG CHAR: 2048
    */
    static void LOG_ERROR(EnumComponentType componentType, const char* format, ...);

    /** Log Fatal
     * MAX LOG CHAR: 2048
    */
    static void LOG_FATAL(EnumComponentType componentType, const char* format, ...);

private:
    static const uint16_t MAX_LOG_CHAR = 2048;
    static void LOG(const char *logMessage);
    static void GetTime(char* buffer);
    static const uint8_t HEADER_LENGTH = 26;
    
};
#endif // _LOGGER_H_