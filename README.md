# Casting and Conversion Among Integers

## Overview

This problem asks you to simulate the process of casting between signed and unsigned
1-byte and 2-byte integers (`char` and `short`). It is important to buid a deep
understanding of how this sort of casting happens, and what it means inside the computer
to convert between one size or type of integer and another. Otherwise, as a programmer,
you could write code that has unexpected results!

Complete all the tasks listed below, and be sure to check the assignment rubric 
to make sure your solution matches what we are looking for. 

Be sure to commit and push your changes frequently: having a copy of the code
that is **not** on the server is safest, and easiest when you need help. See
Homework 0 for guidance on staging, committing, and pushing your code.

### Assignment Rubric

- In `cast_conv.c` (22 pts):
    - Student name and description of file at the top of the file
    - Clean coding style (indentation, spacing, readability, good variable names, etc.)
    - All functions have good quality comments
    - All functions are implemented correctly according to instructions below
    - All debugging statements have been commented out or removed
- In `test.c` (12 pts):
    - Student name and description of file at the top of the file
    - Clean coding style (indentation, spacing, readability, good variable names, etc.)
    - Every test in `main` has a comment that describes what it tests
    - Includes thorough tests that use `assert`:
        - tests each function with both positive/negative inputs or outputs (as appropriate)
        - tests each function with small/large  inputs or outputs
    - Handles dynamically-allocated strings correctly (freeing when done)
    - All debugging and example outputs have been commented out or removed

### Starter Code

- `Makefile`
    - We have provided a Makefile for you; it creates an executable called `cast_conv`.
- `binary_convert2.c`, `binary_convert2.h` 
    - These files are a variation on helper files from the in-class activities. 
    They contain functions that convert `char` and `short` integers into 
    strings of 0's and 1's. Unlike the activity functions, these do not insert
    spaces for readability. You will not need to change this code, just use the functions.
- `cast_conv.c`, `cast_conv.h`
    - These files define eight functions that cast between signed and unsigned
    char and short integers, represented as a string of 0's and 1's. You will 
    implement all eight.
- `test.c`
    - The main program, which will contain your detailed tests of the eight functions
    in `cast_conv.c`.


### Execution

The graders should be able to do the following to build and run your code *without errors*:

    make clean
    make
    ./cast_conv


## Tasks to Complete

### Task 1: Implement casting between signed and unsigned of the same size

For this task you will implement four functions for casting from signed to 
unsigned, and vice versa, for binary strings that represent 1-byte and 2-byte
integers. The functions are listed below by their declarations (you can find 
these declarations in `cast_conv.h`).
```
char *cast_char2uchar(char *binary_char);
char *cast_uchar2char(char *binary_uchar);
char *cast_short2ushort(char *binary_short);
char *cast_ushort2short(char *binary_ushort);
```

Each function takes in a string of 0's and 1's, and returns a new string
of 0's and 1's that represents the new type of data. For example, the
function `cast_char2uchar` takes in a binary string representing a 1-byte
signed integer, and it returns a _new_ binary string representing a 1-byte unsigned
integer.

#### Complete `cast_char2uchar`

When the C compiler casts from signed to unsigned of the same size of integer, 
as the `cast_char2uchar` function does, it does not change the underlying binary
sequence. It simply reinterprets the binary sequence as unsigned rather than signed.

To see this in action, look at the first two examples in `test.c`. Note that both 
`char_s` and `char_u` have the same binary representation in both cases. 

**Experiment with this:** Try assigning `char_s` to be different values, and see what happens. 
Note that the C compiler is already doing implicit casting in a number of places here:
- What happens if you assign `char_s` to a positive integer larger than it can hold?
- What happens if you remove the explicit cast to `(unsigned char)` when we assign `char_u`?
- What happens if you change the code given to `printf`?
    - The `%hhd` placeholder is specifically for printing `char` data (`%hhi` also works)
    - The `%hhu` placeholder is specifically for printing `unsigned char` data
    - Swap the print codes, so that we assign `%hhd` to `char_u` and vice versa
    - What happens?

**Moral of the story:** casting from `char` to `uchar`, or vice versa, doesn't require
the binary string to change at all, we just need to _copy_ the binary string!

Implement `cast_char2uchar` to do the following:
- Create a new binary string of the appropriate length, by calling the right helper function
from `binary_convert2.h` (with any value you like, zero is handy)
- Copy the contents of its input string into the new string
- Return the new string

Implement this, and then uncomment and study the sample test for `cast_char2uchar`
provided in `test.c`. Add additional tests to thoroughly test this function (see rubric).

#### Write the other three size-to-size functions

Follow a similar process to implement `cast_uchar2char`, `cast_short2ushort`, and
`cast_ushort2short`.

### Task 2: Casting from 1-byte to 2-byte integers

For this task, we will focus on converting from 1-byte chars to 2-byte shorts,
either both signed or both unsigned. Thus there are two functions to implement here:
```
char *cast_char2short(char *binary_char);
char *cast_uchar2ushort(char *binary_uchar);
```

We will **not** worry about casting both between sizes and between signed/unsigned 
at the same time!

#### Write `cast_char2short`

When we cast from a shorter integer to a longer one, the shorter one goes into
the low-order bits, and then we must fill in the extra bits with either 0 or 1. 
When the integers are signed, we fill in the high-order bits with whatever the
leftmost (topmost) bit in the shorter integer was: 0 for positive numbers, 1
for negative numbers (using two's complement notation, of course).

Look at examples 3 and 4 in `test.c`, which demonstrate casting from `char`
to `short` on both positive and negative values. Notice the careful use of `printf`
placeholders: `%hd` is the placeholder to use for a signed short integer, and `%hu` for
an unsigned short.

As before, experiment to make sure you understand how these should work.

Implement `cast_char2short` to do the following:
- Create a new binary string to hold the binary representation of a short, 
using functions from binary_convert2.h, with any artbitrary initial value
- Grab the topmost (leftmost) bit from the input string: this will is the sign bit,
and will be needed to fill the high-order bits of the new string
- Loop over the indices into this new binary string
    - if the index is into the high-order byte of the short, assign each position to the sign bit
    - otherwise, copy the value from the input string at the correct index (you'll have to calculate this)
- Return the new string

Write tests for this function in `test.c` that test positive and negative, small and
large inputs.

#### Write `cast_uchar2ushort`

Implement `cast_uchar2ushort` in a similar way. However, with unsigned integers,
the high-order bits are always filled with zero (see examples 5 and 6 in `test.c`).

### Task 3: Casting from 2-byte to 1-byte integers

For this task you will implement two functions that convert from short to char,
either both signed or both unsigned. The functions should work like this:
```
char *cast_short2char(char *binary_short);
char *cast_ushort2uchar(char *binary_ushort);
```

#### Write `cast_short2char`

Look first at Examples 7, 8 and 9 in `test.c` to see how the `cast_short2char`
should work. Notice that the effect of casting is to truncate the longer binary
sequence, simply dropping the high-order bits altogether. If the value of the
longer integer is too big to fit in one byte, the resulting value can be surprising: 
its sign may change, and real information is lost. Nevertheless, this is the behavior we want!

Implement `cast_short2char` as follows:
- Create a new string using the functions from `binary_convert2.h`, for a 1-byte integer
- Loop over the lower-order indices into the short string, and copy them to the
associated positions in the new string
- Return the new string

#### Write `cast_ushort2uchar`

See examples 10 and 11 in `test.c` to see how this function should work. We also
simply truncate the longer string: the results will always be interpreted as positive
values, but may be surprising in the same was as with the signed version.

Implement this function to behave similarly to the previous one.

