#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct object {
	const char* description; // description of object
	const char* tag; // object tag, short form name used for calling object
	struct object* location; // location of object
} OBJECT;

OBJECT objs[] = {
	{"Location 0", "loc0", NULL}, //merged location and object list into one, so these first 7 objects are the locations where players can go
	{"Location 1", "loc1", NULL},
	{"Location 2", "loc2", NULL},
	{"Location 3", "loc3", NULL},
	{"Location 4", "loc4", NULL},
	{"Location 5", "loc5", NULL},
	{"Location 6", "loc6", NULL},

	{"object 0", "gold", &objs[0]}, // a test object, gold coin, location is in "Location 0"
	{"object 1"  , "obj1"  , &objs[1]},
	{"object 2"  , "obj2"  , &objs[1]},
	{"object 3"  , "obj3"  , &objs[1]},
	{"object 4"  , "obj4"  , &objs[1]},
	{"object 5"  , "obj5"  , &objs[1]},
	{"object 6"  , "obj6"  , &objs[1]},
	{"You", "player", NULL}
};

// easy way to reference individual objects
#define loc0 (objs + 0)
#define loc1 (objs + 1)
#define loc2 (objs + 2)
#define loc3 (objs + 3)
#define loc4 (objs + 4)
#define loc5 (objs + 5)
#define loc6 (objs + 6)

#define obj0 (objs + 7)
#define obj1 (objs + 8)
#define obj2 (objs + 9)
#define obj3 (objs + 10)
#define obj4 (objs + 11)
#define obj5 (objs + 12)
#define obj6 (objs + 13)
#define player (objs + 14)