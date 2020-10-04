/**
* Here we make history.
*
* As a kid I begun my journey into technology with a love of plugs
* and wires and I loved to play with them and fondly remember writing
* out boot meessages from my then BIOS on a whiteboard in a manner that
* simulated it but by hand and all the progress and status bars/messages
* that were asscoaited with loading an OS. I always thought it was so complex
* all that stuff and had no idea what that stuff meant.
*
* Time is the biggest gift from the Lord above. It's almost a sin at the same
* darn time seeing as how you want to be older to grasp such concepts of computers
* and technology but wishing so only makes you now yearn for the past, the simpler
* times where I always wondered what mystical smoke powered these machines.
*
* I doubt myself a lot but I'm actually smarter than I think I am, atleast I used
* to doubt myself that much, now I try not too. It has, however, pushed me to better
* understand concepts and all so it is both a curse and a gift having stuff always
* on my mind - never once shutting down (maybe that one time I went out with a
* girl and got pizza but the thoughts never evade me, code is on the mind, I just had
* good reason to shut them out then) - but it sometimes is tiresome.
*
* I've come further than I could have expected. It's probably astounding to me seeing
* how I am actually lazy sometimes (maybe it's relative, maybe others see me as a beast
* with respect to work ethic) now having worked this hard to achieve this but I think
* it isn't just hard work. Hard work is never good if you cannot push yourself even harder
* and you HAVE to love what you do and you MUST do so if you want the process to work
* well. This is because it doesn't seem tiresome then, it seems fun, like - you want to
* actually work and figure it all out.
*
* The thing is you also maybe need to be bored to actually get started as well.
* The statist lockdown for the 'rona is something I disagree with, I bow down to no man
* but God and nobody tells me what to do when it doesn't infringe on someone else. It did,
* however, give me prime time to work on some of my dream projects and actually have
* something to show and say "Yes, that's mine - I created that and I am proud of it".
*
* I feel like a lot of my friends have started to work on their own projects and I am
* so proud of them, whether it be art or code, it's hard getting started sometimes but
* once you start you never want to stop - this is the aim. As for some, I feel the urge
* to help them get started - they don't lack the intellect, definately not, but they lack
* the urge to make time (free time doesn't exist, or is rare and you generally are not in
* the working mood at those times, so it must be during work hours) - I can't see them go
* down a whole of not programming/creating something ever in their life, they must be happy
* - coding makes you happy.
*
* Now, fuck me, I mean don't but _fuck me_ I should start writing this thing. Whoever is
* reading this, make that move - write that code. This isn't "cringe" this is someone
* telling you real-world stuff and not giving you a Python tutorial. You must love what you
* want to do in life, else you're utterly screwed in achieving your dreams in it.
*
* @author Tristan B. Kildaire (deavmi@disroot.org)
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<linux/if_packet.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include "route.h"
#include "redpacket.h"
#include<fcntl.h>

/**
* Data structures
*/
char isActive = 1;
char isForwarding = 0;
struct RoutingTable* routingTable;
struct HostInfo* hostInfo;

void config(char* filename)
{
	/* TODO: Read from the config file */
	int configFD = open(filename, O_RDONLY);

	if(configFD >= 0)
	{
		
	}
	else
	{
		/* TODO: Error handling (return value) */
	}
	
	/* TODO: Use this */
	struct if_nameindex* if_nameindex();
}

/* List of interface names to run on*/
char** interfaceNames;

int main(int argc, char** args)
{
	/* TODO: Run config (move this elsewhere) */
	//config("core.conf");

	/* If there are interfaces specified */
	if(argc > 1)
	{
		interfaceNames = args+1;
	}
	/* If there are no interfaces specified */
	else
	{
		printf("No interfaces to run on have been specified\n");
		return;
	}

	/* Start up the redCore daemon */
	startup();
}

void startup()
{
	/* TODO: Setup redctl sock */
	/* TODO: Spawn a new thread for it */

	/* TODO: Get information from command line or file */
	int interfaceNumber = 1;

	/* Setup address information */
	struct sockaddr_ll addr;
	addr.sll_family = AF_PACKET;
	addr.sll_ifindex = interfaceNumber; /* Set interface to use */
	
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
			/* TODO: Spawn new process here but with vm sharing , clone_thread too probs */
			/* Start the engine routing */
			startEngine(sockFD);	
		}
		/* If the bind failed */
		else
		{
			printf("Error binding socket\n");
		}	
	}
	/* If the socket open failed */
	else
	{
		printf("Error opening socket\n");
	}
}

/**
* Initializes the needed data structures
* and starts the routing engine
*/
void startEngine(int sockFD)
{
	/* Allocate host information (TODO: Sanity check on failed malloc) */
	hostInfo = newHost(); /* TODO: Take in redAddresses */

	/* Allocate a new routing table (TODO: Sanity check on failed malloc) */
	routingTable = newTable();
	
	/* Start the packet loop */
	packetLoop(sockFD);
}

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
char isBroadcastAddress(long address)
{
	/* The broadcast address is all 1-bits/highest-value unsigned long */
	return address == -1;
}

/**
* Accepts a packet into the system
* and passes it up to the correct
* protocol handler
*/
void ingest(struct redPacket* rp)
{
	/* TODO: Implement the redControl handler */

	printf("Ingestion happenine\n");

	/**
	* If the protocol type is 0, then
	* handle the redControl packet
	*/
	if(!rp->type)
	{
		/* TODO: Implement */
	}
	/* Search for a protocol handler */
	else
	{
		/* TODO: Implement protocol handlers array search */	
	}
}

/* TODO: Start packet loop per-device on a new thread (CLONE_VM|CLONE_THREAD) */

/**
* Ethernet packet reader-reactor loop
*
* @param ethFD file descriptor of the opened
* packet socket
*/
void packetLoop(int ethFD)
{
	/* Packet buffer space */
	char* pktBuffer;

	while(isActive)
	{
		/**
		* Block to dequeue a packet
		*
		* This returns the full length of the
		* Ethernet frame (hence the MSG_TRUNC)
		* so we need to do this
		* once before we can do the actual read
		* hence the MSG_PEEK as to not remove
		* the Ethernet frame from the kernel's
		* queue for this process.
		*/
		int frameLength = recv(ethFD, NULL, 0, MSG_PEEK|MSG_TRUNC); /* TODO: Do this with peek (to keep it there) and then trunc for length (then re-read) */
		printf("Received Ethernet frame with length: %u\n", frameLength);

		/* Make sure no receive error occurred */
		if(frameLength < 0)
		{
			printf("recv error");
			continue;
		}
		//else if(frameLength 1+8+8+1+4+4)

		/**
		* Allocate buffer space for the full
		* Ethernet frame and now read dequeue
		* the Ethernet frame into it
		*/
		pktBuffer = malloc(frameLength); /* TODO: NULL check for malloc */
		int recvStatus = recv(ethFD, pktBuffer, frameLength, 0); /* TODO: Check returned value */

		/* Decode the packet */
		struct redPacket* rp = decode(pktBuffer+6+6+2);
		
		/* Free the packet buffer */
		free(pktBuffer);

		/* Print out the redPacket */
		char* pktDescriptor = printPacket(rp);
		printf("%s\n", pktDescriptor);
		free(pktDescriptor);

		/* Only continue if the version is 0 */
		if(!rp->version)
		{
			/* TODO: Destination address handling */

			/**
			* If the address is a broadcast address
			* or one of ours
			*/
			if(isBroadcastAddress(rp->destination) || isLocalAddress(rp->destination))
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
			printf("Dropping redPacket with non-zero version field: %u\n", rp->version);
		}
	}
}