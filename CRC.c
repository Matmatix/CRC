#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

char *intToBinary(int, char *,int);

int main(void)
{
	char* binaryString;
	char c;
	int value, count;
	printf("Enter an integer:\n");
	while((c = getchar())!= '\n')
	{
			value = 10 * value + (c - '0');
	}
	printf("%d\n", value);
	intToBinary(value,binaryString, MAXSIZE);
	printf("%s",binaryString);

}

char *intToBinary(int a, char *buffer,int buf_size)
{
	buffer += (buf_size - 1);

	for(int i = 31; i >= 0; i--)
	{
		*buffer-- = (a & 1) + '0';
		a >>= 1;
	}
	return buffer;
}
