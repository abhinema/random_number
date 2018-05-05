/*
 * random_number_gen.h
 *
 *  Created on: 05-May-2018
 *      Author: abhinema
 */

#ifndef RANDOM_NUMBER_GEN_H_
#define RANDOM_NUMBER_GEN_H_

#include <openssl/rand.h>
#include <typeinfo>

using namespace std;

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

unsigned int stringLength = sizeof(alphanum) - 1;

char genRandom()  {
	unsigned int seed = 0x00beef00;
	unsigned int charLen = 0;
	RAND_seed(&seed, sizeof(seed));
	RAND_bytes((unsigned char *)&charLen, 4);
    return alphanum[charLen % stringLength];
}

template<class T>
void randomNumGen (T &num){
	unsigned int seed = 0x00beef00;
	RAND_seed(&seed, sizeof(seed));
	RAND_bytes((unsigned char *)&num, sizeof(T));
}

//template<class T>
void randomNumGen (char& num){
	unsigned int seed = 0x00beef00;
	unsigned int strLen = 0;
	RAND_seed(&seed, sizeof(seed));
	RAND_bytes((unsigned char *)&strLen, 4);
	num=genRandom();
}

void randomNumGen (string& num){
	num.clear();
	unsigned int seed = 0x00beef00;
	unsigned int strLen = 0;
	RAND_seed(&seed, sizeof(seed));
	RAND_bytes((unsigned char *)&strLen, 4);

// This is to restrict length of string... comment below line if not required.
	if(strLen > 1024) strLen = 1024;

	for(unsigned int c = 0; c < strLen; c++){
		num+=genRandom();
	}
}

#endif /* RANDOM_NUMBER_GEN_H_ */

/* End of File */
