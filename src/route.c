/**
* Route
*
* All routing table related stuff.
*/

#include "route.h"
#include<stdlib.h>

struct RoutingTable* newTable()
{
	struct RoutingTable* table = malloc(sizeof(struct RoutingTable));

	return table;
}