#include "Totp.h"

std::string generateTotpAt(std::string secret, std::chrono::system_clock::time_point timePoint, uint8_t interval = 30, uint8_t digits = 6)
{
    const std::chrono::seconds secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch());
    uint64_t count = secondsSinceEpoch.count() / (long long) interval;

    return generateOtp(secret, count, digits);
}

std::string generateTotpNow(std::string secret, uint8_t interval = 30, uint8_t digits = 6)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    return generateTotpAt(secret, now, interval, digits);
}