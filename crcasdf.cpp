#define POLYNOMIAL 0b1011  /* 11011 followed by 0's */
#include <stdio.h>
#include <cstdint>
int bitCount(unsigned int n);
int crc(int message, int length);
int main()
{
    printf("%x", crc(0b1010001010101010101110010101, 28));
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
    return remainder;

}   /* crcNaive() */
