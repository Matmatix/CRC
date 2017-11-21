#include <iostream>
#include <bitset>
#include <stdio.h>
#define POLYNOMIAL 0b1011  /* 11011 followed by 0's */

using namespace std;
int bitCount(unsigned int n);
int crcNaive(int message);
int main()
{
    std::cout << std::bitset<28>(0xA2AAB9) << endl;
    printf("%x", crcNaive(0xA2AAB9));
}
int
crcNaive(int message)
{
    int remainder;	


    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;
    int const bitSize = bitCount(message);
    /*
     * For each bit position in the message....
     */
    for (int bit = bitSize; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        std::cout << std::bitset<28>(remainder) << endl;
       printf("1011\n");
        if (remainder & (1 << (bitSize - 1)))
        {
            /*
             * XOR the previous remainder with the divisor.
             */
            remainder ^= POLYNOMIAL;
        }

        /*
         * Shift the next bit of the message into the remainder.
         */
        remainder = (remainder << 1);
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return (remainder >> 3);

}   /* crcNaive() */
 int bitCount(unsigned int n) {

    int counter = 0;
    while(n) {
        counter += n % 2;
        n >>= 1;
    }
    return counter;
 }