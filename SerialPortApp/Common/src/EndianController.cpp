#include "EndianController.h"
#include <cstddef>

using namespace Common;

EndianController  *EndianController::s_Instance = NULL;

EndianController::EndianController() : m_IsBigEndian { true }
{
    unsigned int i = 1;
    char *c = (char *)&i;
    if (*c)
        m_IsBigEndian = false;
}

bool EndianController::IsBigEndian()
{
    return m_IsBigEndian;
}

EndianController* EndianController::Instance()
{
    if (s_Instance == NULL)
        s_Instance = new EndianController();
    return s_Instance;
}