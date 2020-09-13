/**
* redPacket
*
* Encoding and decoding tools
*/

#include "redpacket.h"
#include<arpa/inet.h>
#include<stdlib.h>

/**
* Decodes the given bytes into a redPakcet
* struct for ease of use.
*
* @param buffer a char* pointing to
* the buffer
*/
struct redPacket* decode(char* buffer)
{
	/* TODO: Implement me */
	struct redPacket* packet;


	return packet;
}

/**
* Encodes the given redPacket into
* a byte stream that can be sent
*
* @param redPacket the packet to
* encode
*/
char* encode(struct redPacket* packet)
{
	/* Allocate the buffer */
	char* buffer = malloc(1+8+8+1+4+4+packet->length);

	/* Encode the version */
	*buffer = packet->version;

	/* Encode the source address */
	*((long*)(buffer+1)) = packet->source;

	/* Encode the destination address */
	*((long*)(buffer+1+8)) = packet->destination;

	/* Encode the time-to-live value */
	*(buffer+1+8+8) = packet->ttl;

	/* Encode the protocol type */
	*((int*)(buffer+1+8+8+1)) = packet->type;

	/* Encode the length as Big Endian */
	*((int*)(buffer+1+8+8+1+4)) = htonl(packet->length);

	/* Encode the payload (TODO: Perhaps use memcpy) */
	for(unsigned int i = 0; i < packet->length; i++)
	{
		*(buffer+1+8+8+1+4+4+i) = *(packet->payload+i);
	}
	
}