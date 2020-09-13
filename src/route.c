/**
* Route
*
* All routing table related stuff.
*/

#include "route.h"
#include<stdlib.h>

/**
* Allocates a new routing table
* on the heap and returns the
* address to it.
*/
struct RoutingTable* newTable()
{
	struct RoutingTable* table = malloc(sizeof(struct RoutingTable));

	return table;
}