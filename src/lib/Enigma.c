#include "Enigma.h"
#include "EnigmaImpl.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"
#include <string.h>

size_t ascii_to_int(char letter) {
	return letter - 'A';
}

char int_to_ascii(size_t number) {
	return number + 'A';
}

Enigma *new_Enigma(size_t num_rotors, const char **rotors, size_t *rings,
                   size_t *inits, const char *reflector, size_t num_pairs,
                   const char *pairs) {
	
	Enigma *enigma = (Enigma*)malloc(sizeof(Enigma));
	
	enigma->num_rotors = num_rotors;

	enigma->current_settings = (size_t *)malloc(sizeof(size_t) * num_rotors); // test
		for (int i = 0; i < num_rotors; i++) {
			enigma->current_settings[i] = inits[i];
		}
	enigma->inits = (size_t *)malloc(sizeof(size_t) * num_rotors); // test
		for (int i = 0; i < num_rotors; i++) {
			enigma->inits[i] = inits[i];
		}
	enigma->rotors = (char **)malloc(sizeof(char *) * num_rotors); // test
		for (int i = 0; i < num_rotors; i++) {
			enigma->rotors[i] = (char *)malloc(sizeof(char) * 29); // 26 wiring, 1 comma, 1 notch, 1 nullterm
			strcpy(enigma->rotors[i], rotors[i]);
		}
	enigma->rings = rings; // TODO
	enigma->reflector = (char *)malloc(sizeof(char) * 27);
		strcpy(enigma->reflector, reflector);
	enigma->num_pairs = num_pairs;
	enigma->pairs = (char *)pairs;

	return enigma;
}

char *encrypt_Enigma(Enigma *self, char *dst, const char *src) {
	int i = 0;
	char co; // "Object" to be passed through
	do {
		co = src[0];
		co = pb_exchange_letters(co, self->num_pairs, self->pairs);
		//Run into N rotors
		//Reflect
		//Run back into N rotors
		co = pb_exchange_letters(co, self->num_pairs, self->pairs);
		
		
		
		dst[i] = co;
		i++;
	} while (dst[i] != '\0');
	
}

void reset_rotor_Enigma(Enigma *self, size_t *new_setting) {
	for (int i = 0; i < self->num_rotors; i++) {
		self->current_settings[i] = self->inits[i];
		new_setting[i] = self->inits[i];
	}
}

void free_Enigma(Enigma *self) {
	// Make sure to free contents
	free(self->current_settings);
	free(self->inits);
	free(self->rotors);
	free(self->reflector);
	free(self);
}

void get_setting_Enigma(Enigma *self, char *ret) {
	for (int i = 0; i < self->num_rotors; i++) {
		ret[i] = int_to_ascii(self->current_settings[i]);
	}
}

void tick_Enigma(Enigma *self);

void tick_n_Enigma(Enigma *self, size_t n);