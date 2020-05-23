#ifndef _TFTP_CLIENT_CLS_H_
#define _TFTP_CLIENT_CLS_H_

#include <PrimitiveTypesPkg.h>
#include <TftpConstPkg.h>

/**
 * Read Request with options 
 * -> | 01 | filename | 00 | octet | 00 | blksize | 00 | 8192 | 00 |
 * <- | 06 | blksize | 00 | 8192 | 00 |
 * -> | 04 | 00 |
 * <- | 03 | 01 | DATA |
 * -> | 04 | 01 |
 * -> | 03 | 02 | DATA |
 * -> | 04 | 02 |
 * ...
*/

/**
 * Read Request without options
 * -> | 01 | filename | 00 | octet | 00 |
 * <- | 03 | 01 | DATA |
 * -> | 04 | 01 |
 * <- | 03 | 02 | DATA |
 * -> | 04 | 02 |
 * ...
 */

struct TftpOptionsStr
{
    UINT32 Blocksize;
    UINT32 Timeout;
};

struct TftpTransferInformationStr
{
    INT32 Socket;
    UINT32 LastTransferTime;
    UINT32 CurBlk;
    UINT32 TotalSize;
    UINT32 RemainingRetries;
    CHAR Filename[128];
    TftpOptionsStr Options;
};

/**
 * This class uses two separate buffers for sending/receiving packets.
 * Size of the buffers are different as send/receive buffers have different 
 * needs for the packets. In none of the cases large packets come from two
 * separate sides of the connection.
 * (i.e. server sends DATA, OACK and client sends RRQ, ACK packets)
 */
class TftpClientCls
{
public:
    TftpClientCls(CHARP firstBuf, CHARP secondBuf);
    INT32 RequestRead(CCHARP filename, TftpOptionsStr& options);
    UINT32 AppendOptions(CHARP bufToAppend);

private:
    CHARP PrimaryBuffer;
    CHARP SecondaryBuffer;
    TftpTransferInformationStr XferInformation;
};

#endif