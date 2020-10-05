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
#include<sys/errno.h>
#include "redinterface.h"
#include<sched.h>
#include<linux/sched.h>
#include<sys/mman.h>
#include <net/if.h>
#include "redhost.h"

/**
* Prototypes (TODO: Own header file)
*/
void startEngine();
char startProcessor();
int iProcessorLoop();
int eProcessorLoop();
int iPacketLoop();
int ePacketLoop();
void startup(char**, long);
void process(struct redPacket);
void ingest(struct redPacket);
char startSubsystems();

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

char isBroadcastAddress(unsigned long);

int main(int argc, char** args)
{
	/* TODO: Run config (move this elsewhere) */
	//config("core.conf");

	/* If there are interfaces specified */
	if(argc > 1)
	{
		/* Start up the redCore daemon */
		startup(args+1, argc-1);
	}
	/* If there are no interfaces specified */
	else
	{
		printf("No interfaces to run on have been specified\n");
	}
}

/* The redInterfaces */
struct redInterface* interfaces;
long interfaceCount = 0;

void startup(char** interfaceNames, long count)
{
	/* Allocate redInterface */
	interfaces = malloc(sizeof(struct redInterface)*count);

	/* Create all interfaces */
	unsigned long i = 0;
	long interfaceOffset = 0;
	while(i < (unsigned long)count)
	{
		/* Get the current interface's name */
		char* currentInterfaceName = *(interfaceNames+i);
		printf("Setting up interface '%s'...\n", currentInterfaceName);

		/* Get the interface's index */
		int if_index = if_nametoindex(currentInterfaceName);

		/* Only proceed if the interface exists */
		if(if_index)
		{
			printf("Interface index: %u\n", if_index);

			struct redInterface* newInterface = createInterface(if_index);
			if(newInterface)
			{
				*(interfaces+interfaceOffset) = *newInterface;
				interfaceOffset++;	
			}
			else
			{
				printf("Failure to setup PACKET interface for %u!\n", if_index);
			}
		}
		else
		{
			printf("Invalid interface '%s'!\n", currentInterfaceName);
		}

		
		
		i++;
	}

	interfaceCount = interfaceOffset;

	/* TODO: Realloc to resize */

	/* Start the daemon */
	startEngine();
}

char startAPI()
{
	return 1;
}

/**
* Initializes the needed data structures
* and starts the routing engine
*/
void startEngine()
{
	/* Allocate host information (TODO: Sanity check on failed malloc) */
	hostInfo = newHost(); /* TODO: Take in redAddresses */

	/* Allocate a new routing table (TODO: Sanity check on failed malloc) */
	routingTable = newTable();

	/* TODO: Setup redctl sock */

	/* Start all sub-systems (TODO: Return check) */
	startSubsystems();

	while(1)
	{
		
	}
}

/**
* Processor loop
*
* This processes incoming packets from
* the receive queue of the red interfaces
* (moves through each interface via round
* robin).
*
*/
int iProcessorLoop()
{
	/* The current interface */
	struct redInterface* currentInterface;

	/* The current offset into the redInterface array */
	long interfaceID = 0;

	char interfaceName[20];

	/* Loop through each interface, process one packet from receive queue */
	while(1)
	{
		/* Set the current interface */
		currentInterface = interfaces+interfaceID;

		/* Print out some information */
		if_indextoname(currentInterface->index, interfaceName); /* TODO: Error handling, error finding and also overflow */
		printf("[interfaceReceiveProcessor:%s] Beginning\n", interfaceName);


		/* Check if the queue is non-empty */
		if(!isQueueEmpty(currentInterface, RECV))
		{
			printf("[interfaceReceiveProcessor:%s] Queue non empty\n", interfaceName);

			struct redPacket rp = popQueue(currentInterface, RECV);

			/* Print out the redPacket */
			char* pktDescriptor = printPacket(&rp);
			printf("%s\n", pktDescriptor);
			free(pktDescriptor);
			
		}
		/* If the queue is empty */
		else
		{
			printf("[interfaceReceiveProcessor:%s] Queue empty\n", interfaceName);
		}

		printf("Critical processor\n");

		

		
		interfaceID++;

		/* If we are at the end of the interface list */
		if(interfaceID == interfaceCount)
		{
			interfaceID = 0;
		}

		printf("[interfaceReceiveProcessor:%s] Ending (sleeping)\n", interfaceName);

		/* Let the receiver run (or anything but me) */
		sched_yield();

		/* TODO: Don't run all the time also why the fuck would it go brr without anyways */
		sleep(2);
	}
}


int eProcessorLoop()
{
	
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




/**
* Start the sub-systems
*
* Starts the following:
*
* 1. Packet loop (ethernet round robin frame dequeue engine)
* 2. iProcessor (red interface round robin frame processor)
* 3. eProcessor (protocol sender)
* 4. redctl control socket
*/
char startSubsystems()
{
	/* Status of start */
	char status = 1;

	/* List of worker functions */
	int (*workers[])() = {&iProcessorLoop, &eProcessorLoop, &iPacketLoop, &ePacketLoop};

	/* Map a page in for the process (thread-grouped) stack */
	void* processorStacks[4];
	for(int i = 0; i < 4; i++)
	{
		processorStacks[i] = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_GROWSDOWN, -1, 0);

		if(!processorStacks[i])
		{
			status = 0;
			break;
		}
	}

	/* If the pages were mapped successfully */
	if(status)
	{
		/* Start each thread */
		for(int i = 0; i < 4; i++)
		{
			int procPID = clone(workers[i], processorStacks[i]+4096, CLONE_VM|CLONE_THREAD|CLONE_SIGHAND, NULL);//, &h1, &h, &h2);

			if(!processorStacks[i])
			{
				status = 0;
				break;
			}
		}	
	}
	/* If one of the page mappings failed */
	else
	{
		
	}

	return status;
}


/**
* Starts the processor
*/
char startProcessor()
{
	/* Create memory region (and grow it downwards) */
	void* processorStack = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_GROWSDOWN, -1, 0);

	/* If the memory map was successful */
	if(processorStack != -1)
	{
		/* Create new process (sharing memory with me) except the stack (TODO: Add CLONE_THREAD) */
		//int procPID = clone(&processorLoop, processorStack+4096, CLONE_VM|CLONE_THREAD|CLONE_SIGHAND, NULL);//, &h1, &h, &h2);
		// printf("bababba %u\n", procPID);

		return 1;
	}
	else
	{
		return 0;
	}

	
}


int ePacketLoop()
{
	
}


/**
* Ethernet packet reader-reactor loop
*
* It will loop through each interface and if there
* are no frames available it moves onto the next
* interface
*/
int iPacketLoop()
{
	/* Packet buffer space */
	char* pktBuffer;

	/* Current interface we are on */
	struct redInterface* currentInterface = interfaces;
	long curr = 0;


	while(isActive)
	{
		/**
		* TODO: Comment update: Block to dequeue a packet
		*
		* This returns the full length of the
		* Ethernet frame (hence the MSG_TRUNC)
		* so we need to do this
		* once before we can do the actual read
		* hence the MSG_PEEK as to not remove
		* the Ethernet frame from the kernel's
		* queue for this process.
		*/
		long frameLength = recv(currentInterface->sockFD, NULL, 0, MSG_PEEK|MSG_TRUNC|MSG_DONTWAIT);

		/* If there was no error */
		if(frameLength >= 0)
		{
			printf("Received Ethernet frame with length: %lu\n", frameLength);

			/**
			* Allocate buffer space for the full
			* Ethernet frame and now read dequeue
			* the Ethernet frame into it
			*/
			pktBuffer = malloc(frameLength); /* TODO: NULL check for malloc */
			long recvStatus = recv(currentInterface->sockFD, pktBuffer, frameLength, 0); /* TODO: Check returned value */

			/* Decode the packet */
			struct redPacket* rp = decode(pktBuffer+6+6+2);
			
			/* Free the packet buffer */
			free(pktBuffer);

			/* Print out the redPacket */
			char* pktDescriptor = printPacket(rp);
			printf("%s\n", pktDescriptor);
			free(pktDescriptor);


			/* TODO: Above, free (rp) and use it as struct (direct) */
			appendQueue(currentInterface, RECV, *rp);

			/* TODO: Free `rp` (as we copy it in above) */
		}
		/* If there was an error */
		else
		{
			if(errno == EWOULDBLOCK || errno == EAGAIN)
			{
			//	printf("Would block\n");	
			}
			else
			{
			//	printf("Error happened\n");
			}
		}

		/* Increment the current interface position */
		curr++;

		/* If we are at the interface count then we have ended */
		if(curr == interfaceCount)
		{
			curr = 0;
		}
		else
		{
			
		}

		currentInterface = interfaces+curr;
	}
}