#include <stdio.h>


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
    unsigned long long product=1;
    int b=1000000007;
    
    scanf("%d%d%d", &e, &l, &r);

    for(int i=l; i<=r; i++) {
        if(isPrime(i)) {
            for(int j=1; j<=e; j++) {
                product = (product *i) % b;
            }
        }
    }

    printf("%d\n", (int) (product %b));
}