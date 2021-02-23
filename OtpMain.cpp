#include <iostream>

#include "Otp/OtpCode.h"


int main()
{  
  std::vector<OtpCode> codes;

  codes.push_back(OtpCode("Test Key", "JBSWY3DPEHPK3PXPAG25", 30, 6));

  std::cout << "2FA Tokens:" << std::endl;

  for (OtpCode code : codes)
  {
    std::cout << std::endl
              << "Name: " << code.name() << std::endl
              << "Code: " << code.generateNow() << std::endl;
  }

  return 0;
}
