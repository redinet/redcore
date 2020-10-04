/**
* redInterface
*
* Represents an intrerface that can send
* and receive redPackets.
*
* Includes the interface index (sll_ifindex),
* the associated redAddresses
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<linux/if_packet.h>
#include<arpa/inet.h>
#include<stdio.h>
#include "redpacket.h"
#include "redinterface.h"

/**
* Given the interface index this will
* setup a new redInterface
*/
struct redInterface* createInterface(int if_index)
{
	/* The newly created interface */
	struct redInterface* interface = NULL;

	/* Setup address information */
	struct sockaddr_ll addr;
	addr.sll_family = AF_PACKET;
	addr.sll_ifindex = if_index; /* Set interface to use */
	
	/**
	* Set EtherType to listen for redPackets
	* which the ethertype is big-endian-encoded
	* 69 in two bytes.
	*/
	addr.sll_protocol = htons(1569);

	/**
	* Create a new socket
	*
	* We will specify the EtherType later
	* when binding
	*/
	int sockFD = socket(AF_PACKET, SOCK_RAW, 0);

	/* If the socket was opened */
	if(sockFD >= 0)
	{
		/* Bind the Ethernet interface */
		int bindStatus = bind(sockFD, &addr, sizeof(addr));

		/* If the bind succeeded */
		if(!bindStatus)
		{
			/* Create a new redInterface */
			interface = malloc(sizeof(struct redInterface));

			/* Set it up */
			interface->sockFD = sockFD;
		}
		/* If the bind failed */
		else
		{
			/* Do nothing */
		}	
	}
	/* If the socket open failed */
	else
	{
		/* Do nothing */
	}

	return interface;
}