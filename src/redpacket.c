/**
* redPacket
*
* Encoding and decoding tools
*/

#include "redpacket.h"
#include<arpa/inet.h>
#include<stdlib.h>

/**
* Prints out a packet
*/
char* printPacket(struct redPacket* rp)
{
	char* str = malloc(100); /* TODO: Fix */
	sprintf(str, "redPacket [V: %lu, Src: %lu, Dst: %lu]", rp->version, rp->source, rp->destination);

	return str;
}

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
	/* Allocate the data structure */
	struct redPacket* packet = malloc(sizeof(struct redPacket));

	/* Decode the version */
	packet->version = *buffer;

	/* Decode the source address */
	packet->source = *((long*)(buffer+1));

	/* Decode the destination address */
	packet->destination = *((long*)(buffer+1+8));

	/* Decode the time-to-live value */
	packet->ttl = *(buffer+1+8+8);

	/* Decode the protocol type */
	packet->type = *((int*)(buffer+1+8+8+1));

	/* Decode the length (byte swap it native ordering) */
	packet->length = ntohl(*(int*)(buffer+1+8+8+1+4));

	/* Allocate the payload buffer */
	packet->payload = malloc((unsigned int)packet->length);

	/* Copy over the payload into the buffer */
	for(unsigned int i = 0; i < packet->length; i++)
	{
		*(packet->payload+i) = *(buffer+1+8+8+1+4+4+i);
	}

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
	/* Allocate the buffer (TODO: Malloc failure) */
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

	return buffer;
}