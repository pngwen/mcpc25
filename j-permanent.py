#!/usr/bin/env python3
def perm(a, rows, cols):
    if len(rows) == 1:
        r=rows.pop()
        c=cols.pop()
        return a[r][c]
    result=0
    for j in cols:
        r2=set(rows)
        c2=set(cols)
        c2.remove(j)
        r=r2.pop()
        result += a[r][j] * perm(a, r2, c2)
    return result

n=int(input())
a=[]
for i in range(n):
    line=input().split(' ')
    a.append([int(i) for i in line])

print(perm(a, set(range(n)), set(range(n))))