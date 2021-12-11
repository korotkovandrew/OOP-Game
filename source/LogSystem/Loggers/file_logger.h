#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "ilogger.h"
#include <fstream>

class FileLogger : public ILogger
{
public:
    FileLogger();
    ~FileLogger();
    void log(std::string &data);
private:
    std::ofstream out;
};

#endif // FILE_LOGGER_H