#include <stdio.h>

int main()
{
    int hours[25]={0};
    int n;
    int k;
    int start, end;
    int count=0;

    scanf("%d%d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d%d", &start, &end);
        for(int j=start; j<end; j++) {
            hours[j]++;
        }
    }

    for(int i=0; i<25; i++) {
        if(hours[i]>=k) count++;
    }

    printf("%d\n", count);
}