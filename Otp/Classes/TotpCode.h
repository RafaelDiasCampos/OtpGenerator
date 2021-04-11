#include <string>

#include "../Base/Totp.h"

class TotpCode
{
    public:
    TotpCode (std::string name, std::string secret, uint8_t interval, uint8_t digits);
    std::string generateNow();
    std::string generateAt(std::chrono::system_clock::time_point timePoint);

    std::string name () {return m_name;}
    std::string secret () {return m_secret;}
    uint8_t interval () {return m_interval;}
    uint8_t digits () {return m_digits;}

    private:
    std::string m_name;
    std::string m_secret;
    uint8_t m_interval;
    uint8_t m_digits;
};