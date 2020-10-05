/**
* redInterface
*
* Represents an intrerface that can send
* and receive redPackets.
*
* Includes the interface index (sll_ifindex),
* the associated redAddresses
*/

#include<pthread.h>

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

	/* The send queue */
	struct redQueueNode* sendQ;
	pthread_mutex_t sendQLock;

	/* The receive queue */
	struct redQueueNode* recvQ;
	pthread_mutex_t recvQLock;

	/* Attached redAddresses */
	char addrCount;
	long* addrs;

	int index;
};

enum Queue
{
	RECV, SEND
};


struct redInterface* createInterface(int);
char appendQueue(struct redInterface*, enum Queue, struct redPacket);
char isQueueEmpty(struct redInterface*, enum Queue);
struct redPacket popQueue(struct redInterface*, enum Queue);