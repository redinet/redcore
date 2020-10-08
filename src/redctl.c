#include<sys/un.h>
#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>

/**
* Starts up the redctl socket handler 
*
* This is used by the `redctl` program
* to contorl behaviour of the red daemon
*/
char startAPI(char* ctlPath)
{
	/* Status */
	char status = 1;

	/* Open a UNIX domain socket in stream mode */
	int ctlFD = socket(AF_UNIX, SOCK_STREAM, 0);

	/* If the open is successful */
	if(ctlFD != -1)
	{
		/* Set up address to bind to */
		struct sockaddr_un unixAddr;
		unixAddr.sun_family = AF_UNIX;

		/* Copy over the path */
		memcpy(&unixAddr.sun_path, ctlPath, strlen(ctlPath)); /* TODO: Length check on `ctlPath` */

		/* Bind to the given path */
		int bindStatus = bind(ctlFD, &unixAddr, sizeof(struct sockaddr_un));

		/* If the bind is successful */
		if(bindStatus != -1)
		{
			
		}
		/* If the bind is unsuccesful */
		else
		{
			status = 0;
			printf("ctlSock: Bind failed\n");
		}
	}
	/* If the open is unsuccesful */
	else
	{
		status = 0;
		printf("ctlSock: Open failed\n");
	}


	return 1;
}
