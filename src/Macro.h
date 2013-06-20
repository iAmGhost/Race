#pragma once
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define NEW(Type) ((Type *)malloc(sizeof(Type)));
