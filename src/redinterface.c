/**
* redInterface
*
* Represents an intrerface that can send
* and receive redPackets.
*
* Includes the interface index (sll_ifindex),
* the associated redAddresses
*/

struct redInterface
{
	/* TODO: Get correct wdith */
	int index;

	/* Attached redAddresses */
	char addrCount;
	long* addrs;
};