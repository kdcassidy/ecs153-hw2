#include "Plugboard.h"
#include "common.h"
#include <stdbool.h>
#include <stddef.h>

char pb_exchange_letters(const char letter_in, size_t num_pairs, const char *pairs) {
	// if (num_pairs > pairs.size())
	// 	return NULL;
	// or if pairs connect to self
	//	ignore
	// or if a letter is connected to more than one other
	// 	return NULL;

	char letter_out;
	bool is_self = 1;

	for (int i = 0; i < (int)num_pairs; i++) {
		if (letter_in == pairs[2*i]) {
			letter_out = pairs[2*i + 1];
			is_self = 0;
			break;
		} else if (letter_in == pairs[2*i + 1]) {
			letter_out = pairs[2*i];
			is_self = 0;
			break;
		}
	}
	if (is_self) {
		letter_out = letter_in;
	}

	return letter_out;
}
// size_t now int