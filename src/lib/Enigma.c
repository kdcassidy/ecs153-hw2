#include "Enigma.h"
#include "EnigmaImpl.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

Enigma *new_Enigma(size_t num_rotors, const char **rotors, size_t *rings,
                   size_t *inits, const char *reflector, size_t num_pairs,
                   const char *pairs) {
	
	Enigma *ep = (Enigma*)malloc(sizeof(Enigma));
	ep->num_rotors = num_rotors;
	ep->rotors = (char **)rotors; // TODO
	ep->rings = rings; // TODO
	ep->inits = inits; // TODO
	ep->reflector = (char *)reflector; // TODO
	ep->num_pairs = num_pairs; // test
	ep->pairs = (char *)pairs; // test

	return ep;
}

char *encrypt_Enigma(Enigma *self, char *dst, const char *src) {
	int i = 0;
	do {
		dst[0] = pb_exchange_letters(src[0], self->num_pairs, self->pairs);
		i++;
	} while (dst[i] != '\0');
}

void reset_rotor_Enigma(Enigma *self, size_t *new_setting);

void free_Enigma(Enigma *self) {
	// Make sure to free contents
	free(self);
}

void get_setting_Enigma(Enigma *self, char *ret);

void tick_Enigma(Enigma *self);

void tick_n_Enigma(Enigma *self, size_t n);