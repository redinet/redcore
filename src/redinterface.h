/**
* redInterface
*
* Represents an intrerface that can send
* and receive redPackets.
*
* Includes the interface index (sll_ifindex),
* the associated redAddresses
*/

/**
* redQueue
*
* redPacket queue
*/
struct redQueueNode
{
	/* This queue node's packet */
	struct redPacket packet;

	/* The next queue node */
	struct redQueueNode* next;
};

/**
* redInterface
*
* Represents an interface that the red protocol
* runs ontop of. This includes a socket file
* descriptor, an associated address(es) and a
* send and receive queue
*/
struct redInterface
{
	/* Socket file descriptor for this interface */
	int sockFD;

	/* Attached redAddresses */
	char addrCount;
	long* addrs;
};

struct redInterface* createInterface(int);