#include <limits.h>  

unsigned rightrot(unsigned x, int n) {
    unsigned width = sizeof(x) * CHAR_BIT;  
    n %= width;                               
    if (n == 0) 
        return x;
    return (x >> n) | (x << (width - n));
}
