#!/usr/bin/env python3
# Problem D - Baby Shark

line=input().split(' ')
line.append('*********')
curWord=''
curCount=0
maxWord=''
maxCount=0

for word in line:
    if word != curWord:
        if curCount > maxCount:
            maxWord=curWord
            maxCount=curCount
        curWord=word
        curCount=1
    else:
        curCount += 1
print(maxWord)