//write a function that returns x with the n bits beginning from position p set to the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // isolate rightmost n bits of y
    y = y & ~(~0 << n);

    // build a temp that has those bits in the right place
    unsigned temp = ( (x >> (p+1-n)) | y ) << (p+1-n);

    // clear the n bits at p in x, then OR in temp
    unsigned clear_mask = ~( ((1U << n) - 1) << (p+1-n) );
    x = (x & clear_mask) | temp;

    return x;
}
