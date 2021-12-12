#include "log_message.h"

std::ofstream& operator<<(std::ofstream &out, const LogMessage &message)
    {
        out << message.data << std::endl;
        return out;
    }

std::ostream& operator<<(std::ostream &out, const LogMessage &message)
{
    out << message.data << std::endl;
    return out;
}