#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 8

char *int2bin(int, char *,int);

int main(void)
{
	char binaryString[MAXSIZE+1];
	char appended[MAXSIZE+4];
	binaryString[MAXSIZE - 1] = '\0';
	char c;
	int value = 0, count = 0;
	printf("Enter an integer:\n");
	while((c = getchar())!= '\n')
	{
			value = 10 * value + (c - '0');
	}

	printf("%d\n", value);
	int2bin(value, binaryString, MAXSIZE);
	int i;
	for(i = 0; i < MAXSIZE; i++)
	{
		appended[i+3] = binaryString[i];
	}
	for(i = 0; i<3; i++)
	{
		appended[i] = '0';
	}
	printf("%s\n", binaryString);
	printf("%s\n",appended);


}

char *int2bin(int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);

    for (int i = buf_size; i >= 0; i--) {
        *buffer-- = ((a >> (buf_size-i))  & 1) + '0';
    }

    return buffer;
}
