#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char *int2bin(int, char *,int);

char *bitStreamGen(int len);
int main(void)
{
	// Binary string based off input integer
	char binaryString[MAXSIZE+4];
	binaryString[MAXSIZE] = '\0';
	char divisor[] = "1011";
	// Value to append
	char appended[] = "000";
	int i = 0;

	char c;
	printf("Type 0 if you want to insert a binary value\r\n");
	printf("Type 1 if you want to get a random binary value\r\n");
	c = getchar();
	if(c == '1')
	{
		strcpy(binaryString, bitStreamGen(MAXSIZE));
		printf("Your random value is %s\r\n", binaryString);
		i = MAXSIZE;
	}
	else if(c == '0')
	{
		printf("Enter a binary string:\n");
		// Takes in any integer up to maxsize bits
	
		while((c = getchar())!= '\n')
		{
			binaryString[i++] = c;
		}

		binaryString[i]='\0';
		printf("The input value is: %s\n", binaryString);
	}
	if(i < sizeof(divisor))
	{
		printf("Binary string is too small.\n");
		return 0;
	}

	// Copy binaryString to larger array
	strcat(binaryString, appended);
	printf("The appended binary string is: %s\n", binaryString);

	int j;
	for(j=0; j< i-(sizeof(divisor)-1);j++)
	{
		while(binaryString[j] == '0'){
			j++;
		}
		for(i = 0; i < (sizeof(divisor)); i++)
		{
			binaryString[j+i] 	= (binaryString[j+i]-'0')^divisor[i];
		//printf("%s\n", binaryString);
		}
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


char *bitStreamGen(int len)
{
	char *output = malloc(len+1);
	int i;
	for(i = 0; i < len; i++)
	{
		output[i] = (rand() % 2) + '0';
	}
	output[len] = '\0';
	return output;

}
