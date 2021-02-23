#include <chrono>

#include "Otp.h"

std::string generateTotpAt(std::string secret, const std::chrono::system_clock::time_point time, uint8_t interval, uint8_t digits);
std::string generateTotpNow(std::string secret, uint8_t interval, uint8_t digits);