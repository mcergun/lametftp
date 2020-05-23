#ifndef _SOCKET_WRAPPER_H_
#define _SOCKET_WRAPPER_H_

#include <sys/socket.h>
#include <unistd.h>

inline int socket_socket(int domain, int type, int protocol)
{
    return socket(domain, type, protocol);
}

inline int socket_bind(int sockfd, struct sockaddr *my_addr, int addrlen)
{
    return bind(sockfd, my_addr, addrlen);
}

inline int socket_connect(int sockfd, struct sockaddr *serv_addr, int addrlen)
{
    return connect(sockfd, serv_addr, addrlen);
}

inline int socket_listen(int sockfd, int backlog)
{
    return listen(sockfd, backlog);
}

inline int socket_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return accept(sockfd, addr, addrlen);
}

inline int socket_send(int sockfd, const void *msg, int len, int flags)
{
    return send(sockfd, msg, len, flags);
}

inline int socket_recv(int sockfd, void *buf, int len, int flags)
{
    return recv(sockfd, buf, len, flags);
}

inline int socket_sendto(int sockfd, void *msg, int len, unsigned int flags, struct sockaddr *to, socklen_t tolen)
{
    return sendto(sockfd, msg, len ,flags, to, tolen);
}

inline int socket_recfrom(int sockfd, void *buf, int len, unsigned int flags, struct sockaddr *from, socklen_t *fromlen)
{
    return recvfrom(sockfd, buf, len ,flags, from, fromlen);
}

inline int socket_shutdown(int sockfd, int how)
{
    return shutdown(sockfd, how);
}

inline int socket_close(int sockfd)
{
    return close(sockfd);
}

#endif