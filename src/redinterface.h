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
	/* Socket file descriptor for this interface */
	int sockFD;

	/* Attached redAddresses */
	char addrCount;
	long* addrs;
};