#include <iostream>
#include <bitset>
#include <stdio.h>
#define POLYNOMIAL 0b1011  /* 11011 followed by 0's */
#define POLYLENGTH 4

uint8_t crcTable[512];
void tableInit();
int tableCRC(int message, int length);
unsigned createMask(unsigned a, unsigned b, int message);
using namespace std;
int main()
{
    tableInit();
    printf("Table CRC %x\n", tableCRC(0b1010001010101010101110010101, 28));
    printf("Table CRC %x\n", tableCRC(0b0011010111111101, 16));
    printf("%x\n", tableCRC(0b101010100011010111111101, 24));
}
// Extract b - a bits from message, starting at a where a is lsb and b is msb
unsigned createMask(unsigned a, unsigned b, int message)
{
    unsigned r=0;
    int shift;
    for(unsigned i = a; i <= b; i++)
        r |= 1 << i;
    return (r & message) >> a;
}

void tableInit()
{
    int i;
    int message = 0;  
    int remainder;
    uint64_t poly;
    for(i = 0; i < 256; i++)
    {
        message = i;
        remainder = message * 256;
        for(int bit = 16; bit > 8; --bit)
        {
            poly = POLYNOMIAL << (bit - POLYLENGTH);
            if(remainder & (1 << bit - 1))
            {
                remainder ^= poly;
            }
    // Last byte needs to be CRC'd normally, so do a basic CRC for
    // each i
            if((bit - 8) > POLYLENGTH)
            {
                poly = POLYNOMIAL << (bit - POLYLENGTH - 8);
                if(message & (1 << bit - 9))
                {
                    message ^= poly;
                }
            }
        }
    // Store main table in i, but last byte stuff in i + 256 to keep out of way
        crcTable[i] = remainder;
        crcTable[i + 256] = message;
    }
}

int tableCRC(int message, int length)
{
    int i;
    if(length % 8 != 0)
        length = length + (8 - (length % 8));
    int temp = createMask(length - 8, length, message);
    i = length - 8;
    do
    {
        temp = crcTable[temp] ^ createMask(i - 8, i - 1, message);
        i -= 8;
    }while(i >= 8);
    return message << (POLYLENGTH - 1) | crcTable[temp + 256];
}
