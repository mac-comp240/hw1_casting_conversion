/*
 * binary_convert2.h
 * Author: Libby Shoop and Susan Fox (updating)
 * 
 * Prototypes (declarations) for functions in the binary_convert2.c
 * file that are designed to be used by programs.
 * 
 * Note how as a programmer you can simply include this file
 * in order to use the functions in binary_convert.c.
 */



char *char_to_bin_str(char val);
char *uchar_to_bin_str(unsigned char val);
char *short_to_bin_str(short val);
char *ushort_to_bin_str(unsigned short val);

char bin_str_to_char(char *binary_char);
unsigned char bin_str_to_uchar(char *binary_uchar);
short bin_str_to_short(char *binary_short);
unsigned short bin_str_to_ushort(char *binary_ushort);

