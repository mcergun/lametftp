#include <cstring>
#include <cstdio>
#include <socket_wrapper.h>
#include <TftpClientCls.h>

TftpClientCls::TftpClientCls(CHARP firstBuf, CHARP secondBuf) :
    PrimaryBuffer(firstBuf), SecondaryBuffer(secondBuf)
{

}

INT32 TftpClientCls::RequestRead(CCHARP filename, TftpOptionsStr& options)
{
    memset(&XferInformation, 0, sizeof(XferInformation));
    // Save options provided by the user
    XferInformation.Options = options;
    strcpy(XferInformation.Filename, filename);
    XferInformation.Socket = socket_socket(AF_INET, SOCK_DGRAM, 0);
    if (XferInformation.Socket >= 0)
    {
        // Socket has been grabbed, form the request and send it
        // Use secondary buffer to send RRQ and ACK
        UINT32 pos = 1;
        SecondaryBuffer[pos++] = TFTP_OPCODE_RRQ;
        strcpy(SecondaryBuffer + pos, filename);
        pos += (strlen(filename) + 1);
        strcpy(SecondaryBuffer + pos, "octet");
        pos += (strlen("octet") + 1);
        pos += AppendOptions(SecondaryBuffer + pos);
        int ret = socket_sendto(XferInformation.Socket, SecondaryBuffer, pos, 0, NULL, 0);
        if (ret == pos)
        {
            // 
        }
    }
    return 0;
}


UINT32 TftpClientCls::AppendOptions(CHARP bufToAppend)
{
    UINT32 pos = 0;
    // MAX blksize is 32768, 6 length should be sufficient
    CHAR intmd[6] = {0};
    if (XferInformation.Options.Blocksize > 0)
    {
        strcpy(bufToAppend + pos, "blksize");
        pos += (strlen("blksize") + 1);
        sprintf(intmd, "%d", XferInformation.Options.Blocksize);
        strcpy(bufToAppend + pos, intmd);
        pos += (strlen(intmd) + 1);
    }
    if (XferInformation.Options.Timeout > 0)
    {
        strcpy(bufToAppend + pos, "timeout");
        pos += (strlen("timeout") + 1);
        sprintf(intmd, "%d", XferInformation.Options.Timeout);
        strcpy(bufToAppend + pos, intmd);
        pos += (strlen(intmd) + 1);
    }
    return pos;
}
