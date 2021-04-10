#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct object {
	const char* description;
	const char* tag;
	struct object* location;
}
objs[] = {
	{"test location 1", "loc1", NULL},
	{"test location 2", "loc2", NULL},
	{"test coin", "gold", &objs[0]},
	{"test weapon"  , "sword"  , &objs[1]},
};