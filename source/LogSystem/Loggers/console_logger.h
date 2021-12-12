#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H
 
#include <iostream>
#include "ilogger.h"

class ConsoleLogger : public ILogger
{
public:
    ConsoleLogger();
    void log(std::string &);
};

#endif // CONSOLE_LOGGER_H
