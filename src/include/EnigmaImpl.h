#ifndef ENIGMA_IMPL_H
#define ENIGMA_IMPL_H

#include "Enigma.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

struct Enigma {
	size_t num_rotors;
	char **rotors;
	size_t *rings;
	size_t *inits;
	char *reflector;
	size_t num_pairs;
	char *pairs;
};

#endif