CXX=g++
CXXFLAGS=-lssl -lcrypto -g -ggdb -O2 -Wall -I include/cppcodec

TARGET=OtpMain
OBJS=OtpMain.o \
	 Otp/Base/Otp.o \
	 Otp/Base/Totp.o \
	 Otp/Classes/HotpCode.o \
	 Otp/Classes/TotpCode.o

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install: cp $(TARGET) /usr/local/bin

OtpMain.o:

Otp/Base/Otp.o: Otp/Base/Otp.h

Otp/Base/Totp.o: Otp/Base/Totp.h

Otp/Classes/HotpCode.o: Otp/Classes/HotpCode.h

Otp/Classes/TotpCode.o: Otp/Classes/TotpCode.h

$(TARGET): $(OBJS)
	       $(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS) 

.ccp.o:
	$(CXX) -c -o $@ $< $(CXXFLAGS) 