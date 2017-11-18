#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef int bool;
#define true 1
#define false 0
#define MAXSIZE 200
char divisor[] = "10011";
char* bitStreamGen(int len);
char* CRC(char binaryString[], int inLen);
char* interface(char binaryString[]);
bool checkSuccess(char binaryString[]);
int main(void)
{
	// Binary string based off input integer
	int i = 0;
	char *result;
	char binaryString[MAXSIZE + 1];
	char appendedString[MAXSIZE + 5];	

	srand(time(NULL));
	for(i = 0; i < 1; i++)
	{
		strcpy(binaryString, bitStreamGen(MAXSIZE));
		strcpy(appendedString, binaryString);
		printf("%s\r\n", appendedString);
		result = interface(binaryString);
		printf("%s is remainder\r\n", result);
		strcat(appendedString, result);
		printf("%s is result\r\n", appendedString);
		if(checkSuccess(appendedString) == true)
		{
			printf("Success!\r\n");
		}
		else
		{
			printf("Failure :(\r\n");
		}
	}
	free(result);
}

char* interface(char binaryString[])
{
	char *result;
	int i = 0;
	i = MAXSIZE;
	//Can't really check anything if smaller than divisor
	if(i < sizeof(divisor))
	{
		printf("Binary string is too small.\n");
		return 0;
	}

	clock_t begin = clock();
	result = CRC(binaryString, i);
	clock_t end = clock();
	printf("%.3f ms\r\n", (double)(end - begin)*1000/CLOCKS_PER_SEC);
	return result; 
}


char* CRC(char binaryString[], int inLen)
{
	int i = 0;
	int j = 0;
	char* result;
	int divLen = (sizeof(divisor) - 1);
	result = (char*) malloc(5);
	result[4] = '\0';
	// For display/testing purposes
	int displayIndex = 0;
	while(inLen-i >= divLen)
	{
		//Skip if at a zero
		while(binaryString[i] == '0')
			i++;
		if(inLen - i < divLen)
			break;
		///* Used for display purpose only
		printf("%s\r\n", binaryString);
		
		displayIndex = 0;
		while(displayIndex < i)
		{
			printf(" ");
			displayIndex++;
		}
		printf("%s\r\n", divisor, i, inLen, divLen);
	
		//*/ Remove above section for good performance
		// Run through each current val + next divLen spots
		for(j = 0; j < divLen; j++)
		{

			binaryString[j+i] = (binaryString[j+i] - '0') ^ divisor[j];
		}
		i++;
	}
	printf("\r\n");
	result[0] = binaryString[inLen-4];
	result[1] = binaryString[inLen-3];
	result[2] = binaryString[inLen-2];
	result[3] = binaryString[inLen-1];
	return result;
}
bool checkSuccess(char binaryString[])
{
	char* result;
	//result = (char*) malloc(5);
	//result[4] = '\0';
	char* inResult;
	inResult = (char*) malloc(5);
	inResult[4] = '\0';
	inResult[0] = binaryString[MAXSIZE];
	inResult[1] = binaryString[MAXSIZE+1];
	inResult[2] = binaryString[MAXSIZE+2];
	inResult[3] = binaryString[MAXSIZE+3];
	result = CRC(binaryString, (MAXSIZE - 3));
	printf("input: %s\r\n", inResult);
	printf("output: %s\r\n", result);
	return result[0] == binaryString[MAXSIZE-1];
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