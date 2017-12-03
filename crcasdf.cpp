
#define POLYNOMIAL 0b1011  /* 11011 followed by 0's */
#include <stdio.h>
int bitCount(unsigned int n);
int crcNaive(int message, int length);
int main()
{
    printf("%x", crcNaive(0b00110101, 8));
}
int crcNaive(int message, int length)
{
    int remainder;	


    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;
    int poly = POLYNOMIAL << (length - 4);
    /*
     * For each bit position in the message....
     */
    for (int bit = length; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & (1 << bit - 1))
        {
            /*
             * XOR the previous remainder with the divisor.
             */
            remainder ^= poly;
            printf("%x\n", remainder);
            printf("%x\n", poly);
        }
        poly >>= 1;

        /*
         * Shift the next bit of the message into the remainder.
         */
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return remainder;

}   /* crcNaive() */