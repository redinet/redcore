/**
* Route
*
* Type definitions for the route.c
* file
*/

struct Route
{
	long subnet;
	long mask;
	long gateway;
	char* device;
	char metric;

	/**
	* TODO: Source hint if none specified, we will
	* have to consider the api that will be used
	* for how it can be set too etc
	*/
	long sourceAddress;
};

struct RoutingTable
{
	/**
	* TODO: Used linked list next time for route
	* entries
	*/
	int entriesCount;
	struct Route* routes;

	/**
	* TODO: Maybe also route table names (like to
	* enable switching between them)
	*/
};