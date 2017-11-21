
#define POLYNOMIAL 0b1011  /* 11011 followed by 0's */
#include <stdio.h>
int bitCount(unsigned int n);
int crcNaive(int message);
int main()
{
    printf("%x", crcNaive(0b00110101));
}
int
crcNaive(int const message)
{
    int  remainder;	


    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;

    /*
     * For each bit position in the message....
     */
    for (int bit = 8; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & 0x80)
        {
            /*
             * XOR the previous remainder with the divisor.
             */
            remainder ^= POLYNOMIAL;
            printf("%x\n", remainder);
        }

        /*
         * Shift the next bit of the message into the remainder.
         */
        remainder = (remainder << 1);
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return (remainder >> 4);

}   /* crcNaive() */