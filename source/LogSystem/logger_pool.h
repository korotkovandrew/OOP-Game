#ifndef LOGGER_POOL_H
#define LOGGER_POOL_H

#include <vector>
#include <string>
#include <stdexcept>
#include "Loggers/ilogger.h"

class LoggerPool
{
public:
    static LoggerPool *getInstance();

    LoggerPool(const LoggerPool &) = delete;
    LoggerPool& operator=(const LoggerPool &) = delete;

    void submitDataToLoggers(std::string &data);
    void pushLogger(ILogger *logger);
    void clearLoggers();

private:
    LoggerPool() {};
    static LoggerPool* loggerPool;
    std::vector <ILogger*> loggers;
};

#endif // LOGGER_POOL_H
