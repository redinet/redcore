/**
* redPacket
*
* Encoding and decoding tools
*
* Type definitions for redpacket.c
*/

/**
* redPacket
*
* Represents a redNET network packet
*/
struct redPacket
{
	/* Version */
	unsigned char version;

	/* Source address */
	unsigned long source;

	/* Destination address */
	unsigned long destination;

	/* Time-to-live value */
	unsigned char ttl;

	/* Protocol type */
	int type;

	/* Length */
	unsigned int length;

	/* Payload */
	char* payload;
};

struct redPacket* decode(char*);
char* printPacket(struct redPacket*);