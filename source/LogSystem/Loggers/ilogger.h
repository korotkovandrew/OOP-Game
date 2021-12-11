#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "LogMessage/log_message.h"

class ILogger
{
public:
    virtual void log(std::string &) = 0;
};

#endif // LOGGER_H
