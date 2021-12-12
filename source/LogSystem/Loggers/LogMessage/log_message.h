#ifndef LOG_MESSAGE
#define LOG_MESSAGE

#include <iostream>
#include <fstream>

class LogMessage
{
private:
    std::string data;
public:
    LogMessage(std::string &data) : data(data) {}
    friend std::ofstream& operator<<(std::ofstream &out, const LogMessage &message);
    friend std::ostream& operator<<(std::ostream &out, const LogMessage &message);
};

#endif // LOG_MESSAGE
