#include "Otp.h"

#define HASH_MSG_SIZE 8

// Return string containing code from digest and number of digits.
uint64_t getCodeFromDigest(unsigned char* digest, uint8_t digits)
{
    uint8_t offset = digest[19] & 0xf;

    uint64_t code = ((digest[offset + 0] & 0x7f) << 24 |
                     (digest[offset + 1] & 0xff) << 16 |
                     (digest[offset + 2] & 0xff) <<  8 |
                     (digest[offset + 3] & 0xff) <<  0 );

    return code % ( (uint64_t) std::pow(10, digits));
}

// Create message to be hashed. This is done by applying some operations to the
// count value and storing the result in the message array
//
// NOTE: This function assumes that message has enough capacity to store the message.
// To verify how much size is needed, use HASH_MSG_SIZE
void createHashMessage(uint64_t count, unsigned char* message)
{
    int8_t i;

    for (i = (HASH_MSG_SIZE -1); count != 0; i--)
    {
        message[i] = count & 0xFF;
        count >>= 8;
    }
    while (i >= 0)
    {
        message[i] = 0;
        i--;
    }
}

// Decode secret parameter from base 32 and stores it into decodedSecret parameter.
//
// NOTE: This function assumes that decodedSecret has enough capacity to store the decoded value.
// To verify how much size is needed, see getDecodedSizeFromSecret
void decodeSecret(std::string secret, unsigned char* decodedSecret)
{
    std::vector <uint8_t> decodedVector = cppcodec::base32_rfc4648::decode(secret);

    // Copy decodedVector into decodedSecret. This is needed because the decoder function
    // returns a vector while the digest requires a char array
    size_t decodedSecretSize = getDecodedSizeFromSecret(secret);
    for (size_t i = 0; i < decodedSecretSize; i++)
    {
        decodedSecret[i] = decodedVector[i];
    }
}

// Return size of the secret after being decoded
size_t getDecodedSizeFromSecret(const std::string secret)
{
    return (secret.size() * 5) / 8;
}

// Generate OTP code with the parameters given.
// Parameter secret should be in base32 format ([a-z]|[A-Z]|[2-7])
// Parameters interval and digits should be greater than 0
std::string generateOtp (std::string secret, uint64_t count, uint8_t interval = 30, uint8_t digits = 6)
{
    if (digits <= 0) {
        throw "Digits parameter should be greater than 0.";
    }
    if (interval <= 0) {
        throw "Interval parameter should be greater than 0.";
    }

    // Add padding
    secret.insert(secret.end(), secret.length() % 8, '=');

    // Decode secret
    size_t decodedSecretSize = getDecodedSizeFromSecret(secret);
    std::unique_ptr<unsigned char []> decodedSecret = std::make_unique<unsigned char []>(decodedSecretSize);
    decodeSecret(secret, decodedSecret.get());

    // Create message to be hashed
    std::unique_ptr<unsigned char []> message = std::make_unique<unsigned char []>(HASH_MSG_SIZE);
    createHashMessage(count, message.get());

    // Get digest
    uint32_t digestSize;
    std::unique_ptr<unsigned char []> digest = std::make_unique<unsigned char []>(SHA_DIGEST_LENGTH);
    HMAC(EVP_sha1(), decodedSecret.get(), decodedSecretSize, message.get(), HASH_MSG_SIZE, digest.get(), &digestSize);
    
    uint64_t code = getCodeFromDigest(digest.get(), digits);

    std::string codeString = std::to_string(code);
    codeString.insert(codeString.begin(), digits - codeString.length(), '0');

    return codeString;
}