#include "pp_misc.h"

#include <stdlib.h>
#include <time.h>

void pp_seed_unsafe_rand() { srand(time(NULL)); }

int32_t pp_unsafe_rand() { return rand(); }