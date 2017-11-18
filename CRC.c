#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 200
char* bitStreamGen(int len);
char* CRC(char binaryString[], int inLen, char divisor[], int divLen);
char* interface(char binaryString[]);
int main(void)
{
	// Binary string based off input integer
	int i = 0;
	char *result;
	char binaryString[MAXSIZE + 1];
	char appendedString[MAXSIZE + 1];	

	srand(time(NULL));
	for(i = 0; i < 1; i++)
	{
		strcpy(binaryString, bitStreamGen(MAXSIZE));
		strcpy(appendedString, binaryString);
		printf("%s\r\n", appendedString);
		result = interface(binaryString);
		printf("%s is remainder\r\n", result);
		printf("%s\r\n", appendedString);
		strcat(appendedString, result);
		result = interface(appendedString);
		printf("%s is remainder\r\n", result);

	}
	free(result);
}

char* interface(char binaryString[])
{
	char *result;
	char divisor[] = "10011";
	int i = 0;

	strcpy(binaryString, bitStreamGen(MAXSIZE));
	i = MAXSIZE;
	//Can't really check anything if smaller than divisor
	if(i < sizeof(divisor))
	{
		printf("Binary string is too small.\n");
		return 0;
	}

	clock_t begin = clock();
	result = CRC(binaryString, i, divisor, sizeof(divisor) - 1);
	clock_t end = clock();
	printf("%.3f ms\r\n", (double)(end - begin)*1000/CLOCKS_PER_SEC);
	return result; 
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


char* CRC(char binaryString[], int inLen, char divisor[], int divLen)
{
	int i = 0;
	int j = 0;
	char* result;
	result = (char*) malloc(4);
	result[3] = '\0';
	printf("Running...");
	// Remove displayIndex
	//int displayIndex = 0;
	while(inLen-i >= divLen)
	{

		//Skip if at a zero
		while(binaryString[i] == '0')
			i++;
		//Need a better solution for this
		//Should I just use an infinite loop and rely on this check
		//For exiting?
		if(inLen - i < divLen)
			break;
		///* Used for display purpose only
		//printf("%s\r\n", binaryString);
		/*
		displayIndex = 0;
		while(displayIndex < i)
		{
			//printf(" ");
			displayIndex++;
		}
		printf("%s\r\n", divisor, i, inLen, divLen);
	*/


		//*/ Remove above section for good performance
		// Run through each current val + next divLen spots
		for(j = 0; j < divLen; j++)
		{

			binaryString[j+i] = (binaryString[j+i] - '0') ^ divisor[j];
		}
		i++;
	}
	printf("\r\n");
	result[0] = binaryString[inLen-3];
	result[1] = binaryString[inLen-2];
	result[2] = binaryString[inLen-1];
	return result;
}
