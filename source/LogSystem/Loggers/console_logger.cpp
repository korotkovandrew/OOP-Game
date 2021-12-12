#include "console_logger.h"

ConsoleLogger::ConsoleLogger()
{
    std::cout << "Console Logger:" << std::endl;
}

void ConsoleLogger::log(std::string &data) 
{
    std::cout << LogMessage(data);
}
