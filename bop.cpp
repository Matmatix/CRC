#define POLYNOMIAL 0b1011  /* 11011 followed by 0's */
#include <stdio.h>
#include <cstdint>
uint8_t crcTable[256];
int crc(int message, int length);
void tableInit();
int tableCRC(int message, int length);
unsigned createMask(unsigned a, unsigned b, int message);
int main()
{
    printf("%x\n", crc(0b1010001010101010101110010101, 28));
    printf("%x\n", crc(0b0011010111111101, 16));
    printf("%x\n", crc(0b101010100011010111111101, 24));
    //tableInit();
    //printf("%x\n", tableCRC(0b1010001010101010101110010101));
}
int crc(int message, int length)
{
    int remainder;	
    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;
    uint64_t poly;
    /*
     * For each bit position in the message....
     */
    for (int bit = length; bit > 3; --bit)
    {
        poly = POLYNOMIAL << (bit - 4);
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & (1 << bit - 1))
        {
            /*
             * XOR the previous remainder with the divisor.
           1010 0010 1010 1010 1011 1001 0101 011  */
           //0101 0001 0101 0101 0101 1100 1010 1011 
            remainder ^= poly;
            printf("Remainder: %x\n", remainder);
        }
        //printf("Polynomial %x\n", poly);
        /*
         * Shift the next bit of the message into the remainder.
         */
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
 //   printf("Shifting remainder <<: %x\n", message << 3 | remainder);
    return message << 3 | remainder;

}   /* crcNaive() */

void tableInit()
{
    int i;
    int message = 0;  
    int remainder;
    uint64_t poly;
    for(i = 0; i < 256; i++)
    {
        message = i * 256;
        remainder = message;
        for(int bit = 16; bit > 8; --bit)
        {
            printf("remainder: %x\n", remainder);
            poly = POLYNOMIAL << (bit - 4);
            if(remainder & (1 << bit - 1))
            {
                remainder ^= poly;
            }
        }
        printf("Remainder of %x CRC 1011 is %x\n", message, remainder);
        crcTable[i] = remainder;
    }
}

int tableCRC(int message, int length)
{
    int i;
    int temp;
    if(length % 4 != 0)
        length = length + (4- (length % 4));
    i = length - 9;
    while(i > 8)
    {
        temp = createMask(i - 8, i, message);
    }
    return i;
}

unsigned createMask(unsigned a, unsigned b, int message)
{
    unsigned r = 0;
    for (unsigned i = a; i <= b; i++)
    {
        r |= 1 << i;
    }
    return (r & message) >> a;
}
