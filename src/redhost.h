/**
* redHost
*
* Represents a host and the addresses
* attached to it.
*
* Type definitions for redhost.c
*/

struct HostInfo
{
	/* Addresses */
	char addressCount;
	long* addresses;

	/**
	* Subnet and mask for my network
	*
	* TODO: Can use for automatic route insertion for local network route
	* TODO: Use for broadcast address generation
	*/
	long subnet;
	long mask;
};

struct HostInfo* newHost();