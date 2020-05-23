#ifndef _TFTP_CONST_PKG_H_
#define _TFTP_CONST_PKG_H_

#define TFTP_OPCODE_RRQ     1
#define TFTP_OPCODE_WRQ     2
#define TFTP_OPCODE_DATA    3
#define TFTP_OPCODE_ACK     4
#define TFTP_OPCODE_ERR     5
#define TFTP_OPCODE_OACK    6

#define TFTP_DEF_BLKSIZE    8192
#define TFTP_DEF_TIMEOUT    1000
#define TFTP_DEF_MAXRETRIES 5

#endif