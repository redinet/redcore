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

char isActive = 1;

int main()
{
	/* TODO: Setup redctl sock */
	/* TODO: Spawn a new thread for it */

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
		int bindStatus = 0; /* TODO: Add bind call */

		/* If the bind succeeded */
		if(!bindStatus)
		{
			/* Start the packet loop */
			packetLoop(sockFD);
		}
		/* If the bind failed */
		else
		{
			printf("Error binding\n");
		}	
	}
	/* If the socket open failed */
	else
	{
		printf("Error opening socket\n");
	}
}

/**
* Ethernet packet reader-reactor loop
*/
void packetLoop(int ethFD)
{
	while(isActive)
	{
		
	}	
}