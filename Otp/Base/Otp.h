#include <memory>
#include <cmath>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <cppcodec/base32_rfc4648.hpp>

uint64_t getCodeFromDigest(unsigned char* digest, uint8_t digits);
void createHashMessage(uint64_t count, unsigned char* message);
void decodeSecret(std::string secret, unsigned char* decodedSecret);
size_t getDecodedSizeFromSecret(std::string secret);
std::string generateOtp (std::string secret, uint64_t count, uint8_t digits);


