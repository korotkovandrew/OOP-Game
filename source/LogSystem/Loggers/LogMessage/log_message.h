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
    
    friend std::ofstream& operator<<(std::ofstream &out, const LogMessage &message)
    {
        out << "File Logger: [" << message.data << "]" << std::endl;
        return out;
    }

    friend std::ostream& operator<<(std::ostream &out, const LogMessage &message)
    {
        out << "Console Logger: [" << message.data << "]" << std::endl;
        return out;
    }
    
};

#endif // LOG_MESSAGE
