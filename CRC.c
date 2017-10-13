#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char *int2bin(int, char *,int);

int main(void)
{
	// Binary string based off input integer
	char binaryString[MAXSIZE+4];
	int bi;
	binaryString[MAXSIZE] = '\0';
	char divisor[] = "1011";
	// Value to append
	char appended[] = "000";
	char c;
	int value = 0, i = 0;
	printf("Enter a binary string:\n");
	// Takes in any integer up to maxsize bits
	while((c = getchar())!= '\n')
	{
			binaryString[i++] = c;
	}

	binaryString[i]='\0';

	if(i < sizeof(divisor))
	{
		printf("Binary string is too small.\n");
		return 0;
	}

	printf("The input value is: %s\n", binaryString);
	//int2bin(value, binaryString, MAXSIZE);

	// Copy binaryString to larger array
	strcat(binaryString, appended);
	printf("The appended binary string is: %s\n", binaryString);

	int j;
	for(j=0; j< i-(sizeof(divisor)-1);j++)
	{
		while(binaryString[j] == '0'){
			j++;
		}
		printf("%c%c%c%c XOR %s\n", binaryString[j], binaryString[j+1], binaryString[j+2], binaryString[j+3],divisor);
		binaryString[j] 	= (binaryString[j]-'0')^divisor[0];
		binaryString[j+1] = (binaryString[j+1]-'0')^divisor[1];
		binaryString[j+2] = (binaryString[j+2]-'0')^divisor[2];
		binaryString[j+3] = (binaryString[j+3]-'0')^divisor[3];
		//binaryString[j+4] = (binaryString[j+4]-'0')^divisor[4];
		//printf("%s\n", binaryString);
	}
	printf("Final value: %s\n", binaryString);
	return 0;
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
