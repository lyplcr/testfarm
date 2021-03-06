/****************************************************************************/
/* TestFarm                                                                 */
/* Data Logger interface : TCP/IP tools                                     */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 12-AVR-2000                                                    */
/****************************************************************************/

/*
    This file is part of TestFarm,
    the Test Automation Tool for Embedded Software.
    Please visit http://www.testfarm.org.

    TestFarm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TestFarm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TestFarm.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>

#include "tcp.h"
#include "link.h"
#include "tcpip.h"


static char *tcpip_addr(link_item_t *link)
{
  struct sockaddr_in tcpip;
  socklen_t len = sizeof(struct sockaddr_in);
  char *s = "(LOST TCP/IP)";

  if ( getsockname(link->fd_in, (struct  sockaddr *) &tcpip, &len) == 0 )
    s = tcpaddr(NULL, &tcpip);

  return strdup(s);
}


#ifdef USE_SELECT
static void tcpip_fd_set(link_item_t *link, link_fds_t *lfds)
{
  FD_SET(link->fd_in, lfds->rd);

  if ( link->fd_in > lfds->max )
    lfds->max = link->fd_in;
}


static int tcpip_fd_isset(link_item_t *link, fd_set *fds)
{
  if ( FD_ISSET(link->fd_in, fds) )
    return link->fd_in;

  return -1;
}
#endif


static void tcpip_kill(link_item_t *link)
{
  shutdown(link->fd_in, 2);
}


static int tcpip_connect(link_item_t *link, char *argv[], char **errmsg)
{
  char *host = argv[0];
  char *s_port = strchr(host, ':');
  int port;
  int sock;

  /* Get port number */
  if ( s_port == NULL ) {
    *errmsg = "Illegal TCP/IP address specification";
    return -1;
  }
  *(s_port++) = '\0';

  port = atoi(s_port);
  sock = tcpconnect(host, port, 0);
  if ( sock == -1 ) {
    *errmsg = strerror(errno);
    return -1;
  }

  fcntl(sock, F_SETFL, O_NONBLOCK);
  fcntl(sock, F_SETFD, FD_CLOEXEC);

  link->fd_in = sock;
  link->fd_out = sock;
  link->ptr = NULL;

  return 0;
}


/*******************************************************/
/* TCP/IP class initialization                         */
/*******************************************************/

static link_class_t tcpip_lclass = {
  method : "tcp",
  addr : tcpip_addr,
#ifdef USE_SELECT
  fd_set : tcpip_fd_set,
  fd_isset : tcpip_fd_isset,
#endif
  connect : tcpip_connect,
  kill : tcpip_kill,
};


int tcpip_init(void)
{
  /* Register link class */
  link_class_register(&tcpip_lclass);

  return 0;
}


void tcpip_done(void)
{
}
