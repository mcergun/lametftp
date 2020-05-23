CC=gcc
CXX=g++
CFLAGS=-I. -g -Wall

clean:
	rm -f *.o

all: TftpClientCls.o main.cpp
	$(CXX) -o main TftpClientCls.o main.cpp $(CFLAGS)

TftpClientCls.o: TftpClientCls.cpp
	$(CXX) -c -o TftpClientCls.o TftpClientCls.cpp $(CFLAGS)