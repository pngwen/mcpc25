#include <stdio.h>

int mulMod(int a, int b, int mod)
{
    long long prod = (long long)a * (long long)b;   /* ≤ 1e12, fits in 64‑bit */
    return (int)(prod % mod);
}

int powMod(int base, int exp, int mod)
{
    int result = 1;
    base %= mod;                     /* reduce once at start */

    while (exp > 0) {
        if (exp & 1)                 /* if current bit is 1 */
            result = mulMod(result, base, mod);
        base = mulMod(base, base, mod);  /* square */
        exp >>= 1;                   /* next bit */
    }
    return result;
}


int isPrime(int x) 
{
    if(x==2) return 1;
    if(x%2 == 0) return 0;

    for(int f=3; f*f <= x; f+=2) {
        if(x%f == 0 ) return 0;
    }

    return 1;
}


int main()
{
    int e;
    int l;
    int r;
    int product=1;
    int mod=1000000007;
    
    scanf("%d%d%d", &e, &l, &r);

    for(int i=l; i<=r; i++) {
        if(isPrime(i)) {
            product=mulMod(product, powMod(i,e,mod), mod);
        }
    }

    printf("%d\n", product %mod);
}