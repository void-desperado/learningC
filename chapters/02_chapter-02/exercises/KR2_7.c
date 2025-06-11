unsigned invert(unsigned x, int p, int n) {
    return x ^ ( ((1U<<n)-1) << (p+1-n) );
}
