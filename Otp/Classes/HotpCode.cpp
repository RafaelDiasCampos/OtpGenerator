#include "HotpCode.h"

HotpCode::HotpCode (std::string name, std::string secret, uint32_t counter = 0, uint8_t digits = 6) 
: m_name(name), m_secret(secret), m_counter(counter), m_digits(digits)
{

}

std::string HotpCode::generateNext()
{
    return generateOtp(m_secret, m_counter++, m_digits);
}

std::string HotpCode::generateAtCounter(uint32_t counter)
{
    return generateOtp(m_secret, counter, m_digits);
}