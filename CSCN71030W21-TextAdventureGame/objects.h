#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct object {
	const char* description; // description of object
	const char* tag; // object tag, short form name used for calling object
	struct object* location; // location of object
}
objs[] = {
	{"test location 1", "loc1", NULL}, //merged location and object list into one, so these first 2 objects are the locations where players can go
	{"test location 2", "loc2", NULL},
	{"test coin", "gold", &objs[0]}, // a test object, gold coin, location is in "test location 1"
	{"test weapon"  , "sword"  , &objs[1]},
};