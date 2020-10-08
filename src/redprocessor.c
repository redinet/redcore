extern char isForwarding;

#include "redpacket.h"

/**
* Returns true if the given address
* is an address assigned to this redNode
*
* @param true if address is local, false
* otherwise
*/
char isLocalAddress(long address)
{
	return 1; /* TODO: Implement me */
}

/**
* Returns true if the given address
* is a broadcast address
*
* @param true if address is broadcast,
* false otherwise
*/
char isBroadcastAddress(unsigned long address)
{
	/* The broadcast address is all 1-bits/highest-value unsigned long */
	return address == -1;
}

/**
* Accepts a packet into the system
* and passes it up to the correct
* protocol handler
*/
void ingest(struct redPacket rp)
{
	/* TODO: Implement the redControl handler */

	printf("Ingestion happenine\n");

	/**
	* If the protocol type is 0, then
	* handle the redControl packet
	*/
	if(!rp.type)
	{
		/* TODO: Implement */
	}
	/* Search for a protocol handler */
	else
	{
		/* TODO: Implement protocol handlers array search */	
	}
}


void process(struct redPacket rp)
{
	/* Only continue if the version is 0 */
	if(!rp.version)
	{
		/* TODO: Destination address handling */
		/**
		* If the address is a broadcast address
		* or one of ours
		*/
		if(isBroadcastAddress(rp.destination) || isLocalAddress(rp.destination))
		{
			/* Accept the redPacket into the protocol dispatcher */
			printf("Packet destined to us\n");
			ingest(rp);
		}
		/* TODO: Multicast handling */
		/* If the packet wasn't destined to us */
		else
		{
			/* TODO: Check if forwarding is enabled */
			if(isForwarding)
			{
				/* TODO: Implement forwarding */

				/* TODO: Implement ttl check before anything else */
			}
			else
			{
				/* Drop it */
				printf("Received packet with address not destined to us, dropping (forwarding disabled)\n");
			}
		}

				
		/* TODO: Possible source address handling */

		/* TODO: Dependant on destination address, check TTL */
	}
	/* If not, then drop the redPacket */
	else
	{
		printf("Dropping redPacket with non-zero version field: %u\n", rp.version);
	}
}