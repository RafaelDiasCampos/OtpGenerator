CXX=g++
CXXFLAGS=-lssl -lcrypto -g -ggdb -O2 -Wall -I include/cppcodec

TARGET=OtpMain
OBJS=OtpMain.o \
	 Otp/Otp.o \
	 Otp/Totp.o \
	 Otp/OtpCode.o

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install: cp $(TARGET) /usr/local/bin

OtpMain.o:

Otp/Otp.o: Otp/Otp.h

Otp/Totp.o: Otp/Totp.h

Otp/OtpCode.o: Otp/OtpCode.h

$(TARGET): $(OBJS)
	       $(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS) 

.ccp.o:
	$(CXX) -c -o $@ $< $(CXXFLAGS) 