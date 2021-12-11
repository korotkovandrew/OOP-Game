#include "logger_pool.h"

LoggerPool* LoggerPool::loggerPool = nullptr;

LoggerPool *LoggerPool::getInstance()
{
    if (!loggerPool) loggerPool = new LoggerPool();
    return loggerPool;
}

void LoggerPool::submitDataToLoggers(std::string &data)
{
    for (auto l: loggers)
        l->log(data);
}

void LoggerPool::pushLogger(ILogger *logger) {
    for (auto l: loggers)
        if (l == logger) return;
    loggers.push_back(logger);
}

void LoggerPool::clearLoggers()
{
    loggers.clear();
}