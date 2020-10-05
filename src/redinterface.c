/**
* redInterface
*
* Represents an intrerface that can send
* and receive redPackets.
*
* Includes the interface index (sll_ifindex),
* the associated redAddresses
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<linux/if_packet.h>
#include<arpa/inet.h>
#include<stdio.h>
#include "redpacket.h"
#include "redinterface.h"
#include<stdlib.h>
#include<pthread.h>

/**
* Append to the given queue
*
* Double pointer (needed for queue init case)
*/
char appendQueue(struct redInterface* interface, enum Queue queue, struct redPacket packet)
{
	printf("appendQueue: Adding packet to queue...\n");

	/* Status of initialization operation */
	char status = 1;

	/* The chosen queue */
	struct redQueueNode** queueVariable;

	/* Choose the queue and also lock it */
	if(queue == RECV)
	{
		queueVariable = &interface->recvQ;
		pthread_mutex_lock(&interface->recvQLock);
	}
	else
	{
		queueVariable = &interface->sendQ;
		pthread_mutex_lock(&interface->sendQLock);
	}


	/* If the queue is not empty */
	if(*queueVariable)
	{
		/* Create a new queue node */
		struct redQueueNode* newQueueNode = malloc(sizeof(struct redQueueNode));

		/* TODO: Malloc error */

		/* Set the redPacket */
		(*queueVariable)->packet = packet;

		/* Set the next node to NULL */
		(*queueVariable)->next = NULL;
	
		/* TODO: Append to queue */
		struct redQueueNode* currentQueueNode = *queueVariable;
		while(currentQueueNode->next)
		{
			/* Move to the next node */
			currentQueueNode = currentQueueNode->next;
		}

		/* Append the new queue node */
		currentQueueNode->next = newQueueNode;
	}
	/*If the queue is empty */
	else
	{
		/* Initialize the queue */
		*queueVariable = malloc(sizeof(struct redQueueNode));

		/* Set the redPacket */
		(*queueVariable)->packet = packet;

		/* Set the next node to NULL */
		(*queueVariable)->next = NULL;
	}



	if(queue == RECV)
	{
		pthread_mutex_unlock(&interface->recvQLock);
	}
	else
	{
		pthread_mutex_unlock(&interface->sendQLock);
	}


	printf("appendQueue: Adding packet to queue... [done]\n");



	return status;
}

/**
* Given the interface index this will
* setup a new redInterface
*/
struct redInterface* createInterface(int if_index)
{
	/* The newly created interface */
	struct redInterface* interface = NULL;

	/* Setup address information */
	struct sockaddr_ll addr;
	addr.sll_family = AF_PACKET;
	addr.sll_ifindex = if_index; /* Set interface to use */
	
	/**
	* Set EtherType to listen for redPackets
	* which the ethertype is big-endian-encoded
	* 69 in two bytes.
	*/
	addr.sll_protocol = htons(1569);

	/**
	* Create a new socket
	*
	* We will specify the EtherType later
	* when binding
	*/
	int sockFD = socket(AF_PACKET, SOCK_RAW, 0);

	/* If the socket was opened */
	if(sockFD >= 0)
	{
		/* Bind the Ethernet interface */
		int bindStatus = bind(sockFD, &addr, sizeof(addr));

		/* If the bind succeeded */
		if(!bindStatus)
		{
			/* Create a new redInterface */
			interface = malloc(sizeof(struct redInterface));

			/* Set it up */
			interface->sockFD = sockFD;

			/* Zero the queues */
			interface->sendQ = NULL;
			interface->recvQ = NULL;

			/* Setup queue mutexes */
			pthread_mutex_init(&interface->sendQLock, 0);
			pthread_mutex_init(&interface->recvQLock, 0);
		}
		/* If the bind failed */
		else
		{
			/* Do nothing */
		}	
	}
	/* If the socket open failed */
	else
	{
		/* Do nothing */
	}

	return interface;
}