//write a fucntion that gets n bits of a word x beginning from position p
#include <stdio.h>
unsigned getbits(unsigned wordFromWhichBitsAreFetched,int positionFromWhichBitsAreFetched, int noOfBitsToBeFetched){
    wordFromWhichBitsAreFetched = wordFromWhichBitsAreFetched >> (positionFromWhichBitsAreFetched+1-noOfBitsToBeFetched);
    return wordFromWhichBitsAreFetched & ~(~0 << noOfBitsToBeFetched);
}