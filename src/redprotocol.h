/**
* Represents a redProtocol
*
* Associates protocol number to
* name and a socket of which is
* to be used to send to when traffic
* for this protocol arrives and is
* to be processed.
*/

struct redProtocol
{
	/* The protocol number */
	int protocol;

	/* The protocol's name */
	char* name;	

	/* UNIX domain path  */
	char* domainPath;
};



struct redProtocolListNode
{
	/* This protocol */
	struct redProtocol protocol;
	
	/* Next protocol */
	struct redProtocolListNode* next;
};

void addProtocol(struct redProtocol);