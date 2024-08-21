/*
 * binary_convert.c
 * 
 * Author:  Libby Shoop, updated by Susan Fox (2024)
 * 
 * Functions that determine the bit representation of values of the C integral types:
 * 
 *    char, short, int, long
 * and the unsigned versions of each
 * 
 * a special conversion for half a byte, or a nibble, is also included.
 * 
 * Note: some of this code will make more sense a bit later in the course,
 *       and you will see some of it even later in the semester.
 *       So you do not have to read and understand this all yet.
 * 
 * Important: each of these functions allocates memory for the string that it
 *            returns, so when you are done using the string in your code,
 *            you need to 'free' it. (stdlib.h)
 */

#include <stdlib.h>   // size_t (from stddef.h included within stdlib.h), malloc
#include <stdio.h>    // printf
#include <string.h>    // strcat and strcpy

#include "binary_convert2.h"


// private to this file, so left out of binary_convert2.h
char *convert_to_string(long val, int bits);


// -------------------- char convert ------------------------

/**
 * Given a char, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
 * 
 * Memory is allocated for the return string and must be freed after use.
 */
char *char_to_bin_str(char val) {
	size_t bytes = sizeof(char);
	size_t bits = 8;   // bytes << 3;      // shift left by 3 is same as *8
	
	char *result = convert_to_string((long)val, bits);
 
	return result;
}

// -------------------- unsigned char convert ------------------------

/**
 * Given an unsigned char, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char *uchar_to_bin_str(unsigned char val) {
	size_t bytes = sizeof(unsigned char);
	size_t bits = 8;  // bytes << 3;      // shift left by 3 is same as *8
	
	char *result = convert_to_string((long)val, bits);
 
	return result;
}

// ------------------------ short convert ------------------------

/**
 * Given a short, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char *short_to_bin_str(short val) {
	size_t bytes = sizeof(short);
	size_t bits = 16;  // bytes << 3;      // shift left by 3 is same as *8
	
	char *result = convert_to_string((long)val, bits);
 
	return result;
}

// ------------------------ unsigned short convert ------------------------
/**
 * Given an unsigned short, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char *ushort_to_bin_str(unsigned short val) {
	size_t bytes = sizeof(unsigned short);
	size_t bits = 16;  // bytes << 3;      // shift left by 3 is same as *8
	
	char *result = convert_to_string((long)val, bits);
 
	return result;
}

// ---------------------- helper for all functions above  ---------------------

/*
 * Convert a val of length bits into a string.
 * The string should already be long enough to hold a 
 * "pretty" version, where every 4 bits are separated by a space.
 */
char *convert_to_string(long val, int bits) {
	// note that the input is a long so that we can convert any possible integral
	// type using this one function
	
	// will create the string with a space after every 4th bit,
	// so add extra length and a space for the trailing null.
	char *result = (char *)malloc(sizeof(char) * (bits + 1));
	strcpy(result, "");
	
	// later on you will see why we 'widen' to use long values
	// to ensure that all lengths work
	long bit;
	long one = 1;
	
	for(int i = bits-1; i >= 0; --i) {
		
		// this operation will be clearer later
		bit = val & (one << i);
	
		if (bit) {
			strcat(result, "1");
		} else {
			strcat( result, "0");
		}	
		
		// if (i%4 == 0 && i > 0) {
		// 	strcat(result, " ");
		// }
		
	}
	
	return result;
}
