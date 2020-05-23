#include <iostream>
#include <cstring>
#include <TftpClientCls.h>

int main(int argc, char **argv)
{
    std::cout << "Hello world!" << std::endl;
    CHAR buf1[512 + 2] = {0};
    CHAR buf2[256] = {0};
    TftpClientCls tftpCli(buf1, buf2);
    TftpOptionsStr opts;
    opts.Blocksize = 512;
    opts.Timeout = 1000;
    tftpCli.RequestRead("Hello", opts);
    CHARP loc = buf1;
    std::cout << loc << std::endl;
    loc += strlen(loc) + 1;
    std::cout << loc << std::endl;
    loc += strlen(loc) + 1;
    std::cout << loc << std::endl;
    loc += strlen(loc) + 1;
    std::cout << loc << std::endl;
    
}