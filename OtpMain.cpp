#include <iostream>

#include "Otp/Classes/TotpCode.h"
#include "Otp/Classes/HotpCode.h"


int main()
{  
  std::vector<TotpCode> totpCodes;

  totpCodes.push_back(TotpCode("Test Key", "JBSWY3DPEHPK3PXPAG25", 30, 6));

  std::cout << "2FA Tokens:" << std::endl;

  for (TotpCode code : totpCodes)
  {
    std::cout << std::endl
              << "Name: " << code.name() << std::endl
              << "Code: " << code.generateNow() << std::endl;
  }

  HotpCode hotpCode("Test Key", "JBSWY3DPEHPK3PXPAG25", 0, 8);

  std::cout << "HOTP Tokens:" << std::endl;
  std::cout << std::endl
            << "Name: " << hotpCode.name() << std::endl
            << "Codes: " << std::endl;
  
  for (int i = 0; i < 10; i++)
  {
    std::cout << i << ": " << hotpCode.generateNext() << std::endl;
  }

  return 0;
}
