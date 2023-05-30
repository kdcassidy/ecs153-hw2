#ifndef ENIGMA_IMPL_H
#define ENIGMA_IMPL_H

#include "Enigma.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

size_t ascii_to_int(char letter);
char int_to_ascii(size_t number);

struct Enigma {
	size_t num_rotors;
	char **rotors;
	size_t *rings;
	size_t *inits;
	char *reflector;
	size_t num_pairs;
	char *pairs;

	size_t *current_settings;
};

#endif