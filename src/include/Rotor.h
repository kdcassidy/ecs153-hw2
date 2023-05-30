#ifndef ROTOR_H
#define ROTOR_H

#include "common.h"

char forward_rotor_shuffle(const char letter_in, const char *rotor, size_t setting);
char reverse_rotor_shuffle(const char letter_in, const char *rotor, size_t setting);

#endif