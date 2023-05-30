#include "Rotor.h"
#include "common.h"

char forward_rotor_shuffle(const char letter_in, const char *rotor, size_t setting) {
	int letter_in_num = (int)(letter_in - 'A');
	return rotor[(letter_in_num + setting) % 26];
}

char reverse_rotor_shuffle(const char letter_in, const char *rotor, size_t setting) {
	int letter_in_num = (int)(letter_in - 'A');
	//int corrected_letter_num = (letter_in_num + setting) % 26;
	int ri;
	for (int i = 0; i < 26; i++) {
        if (rotor[i] == letter_in_num + 'A') {
            ri = i;
            break;
        }
    }
	int out_i = (ri - setting + 26) % 26;
	return (char)(out_i + 'A');
}