#include "Reflector.h"
#include "common.h"
#include "stdlib.h"
#include "string.h"


char reflector_shuffle(const char letter_in, const char *reflector) {
	return reflector[(int)(letter_in - 'A')];
}