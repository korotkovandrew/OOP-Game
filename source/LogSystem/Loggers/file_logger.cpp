#include "file_logger.h"

FileLogger::FileLogger()
{
    out.open("../log/log.txt", std::ofstream::trunc);
    out << "File Logger:" << std::endl;
}

FileLogger::~FileLogger()
{
    out.close();
}

void FileLogger::log(std::string &data) 
{
    out << LogMessage(data);
}
