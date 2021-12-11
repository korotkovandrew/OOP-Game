#include "console_logger.h"

void ConsoleLogger::log(std::string &data) 
{
    std::cout << LogMessage(data);
}
