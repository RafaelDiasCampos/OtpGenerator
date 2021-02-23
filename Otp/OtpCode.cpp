#include "OtpCode.h"

OtpCode::OtpCode (std::string name, std::string secret, uint8_t interval = 30, uint8_t digits = 6) 
: m_name(name), m_secret(secret), m_interval(interval), m_digits(digits)
{

}

std::string OtpCode::generateNow()
{
    return generateTotpNow(m_secret, m_interval, m_digits);
}