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
	char version;

	/* Source address */
	long source;

	/* Destination address */
	long destination;

	/* Time-to-live value */
	char ttl;

	/* Protocol type */
	int type;

	/* Length */
	unsigned int length;

	/* Payload */
	char* payload;
};

struct redPacket* decode(char*);
char* printPacket(struct redPacket*);