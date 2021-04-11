#include <string>

#include "../Base/Otp.h"

class HotpCode
{
    public:
    HotpCode (std::string name, std::string secret, uint32_t counter, uint8_t digits);
    std::string generateNext();
    std::string generateAtCounter(uint32_t counter);

    std::string name () {return m_name;}
    std::string secret () {return m_secret;}
    uint32_t counter () {return m_counter;}
    uint8_t digits () {return m_digits;}

    private:
    std::string m_name;
    std::string m_secret;
    uint8_t m_counter;
    uint8_t m_digits;
};