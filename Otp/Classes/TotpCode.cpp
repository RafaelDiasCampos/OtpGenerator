#include "TotpCode.h"

TotpCode::TotpCode (std::string name, std::string secret, uint8_t interval = 30, uint8_t digits = 6) 
: m_name(name), m_secret(secret), m_interval(interval), m_digits(digits)
{

}

std::string TotpCode::generateNow()
{
    return generateTotpNow(m_secret, m_interval, m_digits);
}

std::string TotpCode::generateAt(std::chrono::system_clock::time_point timePoint)
{
    return generateTotpAt(m_secret, timePoint, m_interval, m_digits);
}