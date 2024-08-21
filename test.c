/*
 * TODO: File description and your name go here
 */

/* Include statement */
#include <stdio.h>   // for printf
#include <stdlib.h>  // for free
#include <string.h>  // for string operations such as strcmp
#include <assert.h>  // for the assert function

#include "binary_convert2.h"
#include "cast_conv.h"

void run_examples();  // Helper that runs examples showing how casting works

int main() {
    char char_s;
    unsigned char char_u;
    short short_s;
    unsigned short short_u;
    char *binA, *binB;

    // TODO: Comment out or remove the examples below when you are writing your own tests
    run_examples();

    // --------------------------------------------------------
    // Tests for cast_char2uchar
    // TODO: Uncomment the test below and use as a model
    // char_s = 35;
    // binA = char_to_bin_str(char_s);
    // binB = cast_char2uchar(binA);
    // // New string must be new (not same as input string), and should equal "00100011"
    // assert(binA != binB && strcmp(binB, "00100011") == 0);
    // free(binA);
    // free(binB);


    // TODO Add many more tests here for all eight functions

    return 0;
}


/*
 * Runs a series of examples to investigate casting between signed and unsigned
 * chars, and between chars and shorts, both signed and unsigned. 
 * Just to help build intuitions about how casting works on binary representations.
 */
void run_examples() {
    char char_s;
    unsigned char char_u;
    short short_s;
    unsigned short short_u;
    char *binA, *binB;

    printf("\n======== Converting signed chars to unsigned chars\n");
    // Example 1: built-in conversion between signed and unsigned chars
    char_s = 35;
    char_u = (unsigned char) char_s;
    binA = char_to_bin_str(char_s);
    binB = uchar_to_bin_str(char_u);
    printf("char_s = %hhd  char_u = %hhu\n", char_s, char_u);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    // Example 2: built-in conversion between signed and unsigned chars, negatives!
    char_s = -70;
    char_u = (unsigned char) char_s;
    binA = char_to_bin_str(char_s);
    binB = uchar_to_bin_str(char_u);
    printf("char_s = %hhd  char_u = %hhu\n", char_s, char_u);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    printf("\n======== Converting signed chars to signed shorts\n");
    // Example 3: built-in conversion between char and short
    char_s = 100;
    short_s = (short) char_s;
    binA = char_to_bin_str(char_s);
    binB = short_to_bin_str(short_s);
    printf("char_s = %hhd  short_s = %hd\n", char_s, short_s);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    // Example 4: built-in conversion between char and short
    char_s = -89;
    short_s = (short) char_s;
    binA = char_to_bin_str(char_s);
    binB = short_to_bin_str(short_s);
    printf("char_s = %hhd  short_s = %hd\n", char_s, short_s);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    printf("\n======== Converting unsigned chars to unsigned shorts\n");
    // Example 5: built-in conversion between uchar and ushort
    char_u = 65;
    short_u = (unsigned short) char_u;
    binA = uchar_to_bin_str(char_u);
    binB = ushort_to_bin_str(short_u);
    printf("char_u = %hhu  short_u = %hu\n", char_u, short_u);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    // Example 6: built-in conversion between uchar and ushort
    char_u = 153;
    short_u = (unsigned short) char_u;
    binA = uchar_to_bin_str(char_u);
    binB = ushort_to_bin_str(short_u);
    printf("char_u = %hhu  short_u = %hu\n", char_u, short_u);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    printf("\n======== Converting signed shorts to signed chars\n");
    // Example 7: built-in conversion between short and char
    short_s = 37;
    char_s = (char) short_s;
    binA = short_to_bin_str(short_s);
    binB = char_to_bin_str(char_s);
    printf("short_s = %hd  char_s = %hhd\n", short_s, char_s);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    // Example 8: built-in conversion between short and char
    short_s = 1237;
    char_s = (char) short_s;
    binA = short_to_bin_str(short_s);
    binB = char_to_bin_str(char_s);
    printf("short_s = %hd  char_s = %hhd\n", short_s, char_s);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);
 
    // Example 9: built-in conversion between short and char
    short_s = -150;
    char_s = (char) short_s;
    binA = short_to_bin_str(short_s);
    binB = char_to_bin_str(char_s);
    printf("short_s = %hd  char_s = %hhd\n", short_s, char_s);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    printf("\n======== Converting unsigned shorts to unsigned chars\n");
    // Example 10: built-in conversion between ushort and uchar
    short_u = 37;
    char_u = (unsigned char) short_u;
    binA = short_to_bin_str(short_u);
    binB = char_to_bin_str(char_u);
    printf("short_u = %hu  char_u = %hhu\n", short_u, char_u);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);

    // Example 11: built-in conversion between ushort and uchar
    short_u = 3562;
    char_u = (unsigned char) short_u;
    binA = short_to_bin_str(short_u);
    binB = char_to_bin_str(char_u);
    printf("short_u = %hu  char_u = %hhu\n", short_u, char_u);
    printf("binA = %s  binB = %s\n", binA, binB);
    free(binA);
    free(binB);
 
}