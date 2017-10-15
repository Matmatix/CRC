#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 200

char *bitStreamGen(int len);
int CRC(char binaryString[], int inLen, char divisor[], int divLen);
int main(void)
{
	// Binary string based off input integer
	char binaryString[MAXSIZE+4];
	binaryString[MAXSIZE] = '\0';
	char divisor[] = "1011";
	srand(time(NULL));

	
	int i = 0;
	printf("Type 0 if you want to insert a binary value\r\n");
	printf("Type 1 if you want to get a random binary value\r\n");
	char c = getchar();
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

		c = getchar();	
		while((c = getchar())!= '\n')
		{
			//i servers as binaryString's length
			binaryString[i++] = c;
		}

		binaryString[i]='\0';
		printf("The input value is: %s\n", binaryString);
	}
	//Can't really check anything if smaller than divisor
	if(i < sizeof(divisor))
	{
		printf("Binary string is too small.\n");
		return 0;
	}


	CRC(binaryString, i, divisor, sizeof(divisor) - 1);
	printf("Final value: %s\n", binaryString);
	return 0;
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


int CRC(char binaryString[], int inLen, char divisor[], int divLen)
{
	int i = 0;
	int j = 0;
	// Remove displayIndex 
	int displayIndex = 0;
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
		// Used for display purpose only
	/*	
		printf("%s\r\n", binaryString);
		displayIndex = 0;
		while(displayIndex < i)
		{
			printf(" ");	
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

	return 0;
}
