// ipc.c

#include "ipc.h"
#include <stdio.h>

#ifdef __cplusplus
namespace ipc {
extern "C" {
#endif // __cplusplus

void ex1(void) {
	printf("Running exercise one\n");
}

#ifdef __cplusplus
}
}
#endif // __cplusplus
