/**
* Protocol handler management
*/

#include "redprotocol.h"
#include<stdlib.h>
#include<stdio.h>

/* Head of the linked-list */
struct redProtocolListNode* protocolHandlerChain;

void addProtocol(struct redProtocol protocol)
{
	/* Allocate a new node */
	struct redProtocolListNode* newNode = malloc(sizeof(struct redProtocolListNode));

	/* Set the protocol */
	newNode->protocol = protocol;

	/* Set the next to NULL */
	newNode->next = NULL;

	/* If the list is not empty */
	if(protocolHandlerChain)
	{
		struct redProtocolListNode* currentNode = protocolHandlerChain;

		while(currentNode->next)
		{
			currentNode = currentNode->next;
		}


		currentNode->next = newNode;
	}
	/* If the list is empty */
	else
	{
		/* Make the new node the list */
		protocolHandlerChain = newNode;
	}

	printf("redProtocol: Added new protocol handler '%s'\n", protocol.name);
}