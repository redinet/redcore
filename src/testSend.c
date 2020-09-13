#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<linux/if_packet.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include "redpacket.h"

int main()
{
	struct redPacket* rp = malloc(sizeof(struct redPacket));

	char* bytes = encode(rp);


	/* TODO: Get information from command line or file */
	int interfaceNumber = 2;

	/* Setup address information */
	struct sockaddr_ll addr;
	addr.sll_family = AF_PACKET;
	addr.sll_ifindex = interfaceNumber; /* Set interface to use */

	/**
	* Set EtherType to listen for redPackets
	* which the ethertype is big-endian-encoded
	* 69 in two bytes.
	*/
	addr.sll_protocol = htons(69); 

	int protocol = htonl(1569);
	char* protocolBytes = (char*)&protocol;

	int sockFD = socket(AF_PACKET, SOCK_RAW, 0);

	int bindStatus = bind(sockFD, &addr, sizeof(addr));

	/* Send the Ethernet frame */
	char* bytesFull = bytes;
	char eth[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,*(protocolBytes+2),*(protocolBytes+3)};
	send(sockFD, eth, 14, 0);

}