extern "C" {
#include "Enigma.h"
#include "EnigmaImpl.h"
#include "common.h"
}
#include <gtest/gtest.h>

namespace {

Enigma *get_default_Enigma() {
  const char *rotors[] = {ROTOR_I, ROTOR_II, ROTOR_III};
  size_t rings[] = {1, 5, 3};
  size_t inits[] = {1, 5, 3};
  return new_Enigma(3, rotors, rings, inits, I_UKW_A, 5, "ECSONFIVTH");
}

TEST(EnigmaTests, GetReset) {
	Enigma *enigma = get_default_Enigma();
	char retc[enigma->num_rotors];
	size_t reti[enigma->num_rotors];
	int same = 1;

	get_setting_Enigma(enigma, retc);
	char exp0[enigma->num_rotors] = {'B', 'F', 'D'};
	for (int i = 0; i < enigma->num_rotors; i++) {
		EXPECT_EQ(retc[i], exp0[i]);
	}
	
	for (int i = 0; i < enigma->num_rotors; i++) {
		enigma->current_settings[i] = 0;
	}

	same = 1;
	get_setting_Enigma(enigma, retc);
	char exp1[enigma->num_rotors] = {'A', 'A', 'A'};
	for (int i = 0; i < enigma->num_rotors; i++) {
		EXPECT_EQ(retc[i], exp1[i]);
	}

	same = 1;
	reset_rotor_Enigma(enigma, reti);
	size_t exp2[enigma->num_rotors] = {1, 5, 3};
	for (int i = 0; i < enigma->num_rotors; i++) {
		EXPECT_EQ(reti[i], exp2[i]);
	}
}

}