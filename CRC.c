#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 8

char *int2bin(int, char *,int);

int main(void)
{
	// Binary string based off input integer
	char binaryString[MAXSIZE+1];
	binaryString[MAXSIZE] = '\0';
	// Binary string with appended value space
	char appended[MAXSIZE+4];
	char c;
	int value = 0, i = 0;
	printf("Enter an integer:\n");
	// Takes in any integer up to maxsize bits
	while((c = getchar())!= '\n')
	{
			value = 10 * value + (c - '0');
	}

	printf("The input value is: %d\n", value);
	int2bin(value, binaryString, MAXSIZE);
	// Copy binaryString to larger array	
	for(i = 0; i < MAXSIZE; i++)
	{
		appended[i+3] = binaryString[i];
	}
	// Put desired appended values (000 in this case) at end
	for(i = 0; i<3; i++)
	{
		appended[i] = '0';
	}
	// Null terminate your stuff
	appended[MAXSIZE+3] = '\0';
	printf("The appended binary string is: %s\n", appended);

}

char *int2bin(int a, char *buffer, int buf_size) {
    // Move the pointer for buffer to the front
    buffer += (buf_size - 1);

    // Travel entire integer and shift by 1..bufsize, bit-wise and with 1
    // Add '0' to make a character instead of int for convenience
    for (int i = buf_size; i >= 0; i--) {
        *buffer-- = ((a >> (buf_size-i))  & 1) + '0';
    }

    return buffer;
}
