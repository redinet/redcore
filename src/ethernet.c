/**
* Ethernet tools
*
* Encoding and decoding done eaisly
* for Ethernet frames
*/

char* createFrame(int length, char* redPacket, char* to, char* from)
{
	/* Allocate the buffer */
	char* ethernetFrame = malloc(6+6+2+(unsigned int)length);

	
}