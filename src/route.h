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
}

struct RoutingTable
{
	
}