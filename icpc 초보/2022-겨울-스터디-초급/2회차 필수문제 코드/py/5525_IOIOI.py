import sys
input = sys.stdin.readline

n = int(input())
n = 2*n + 1
m = int(input())
s = input()

answer = 0
MOD = 2**64

pValue = 0 # 패턴의 해쉬값
x = 1
for i in range(n):
    if i%2 == 0:
        pValue += (ord('I')-ord('A')+1) * x
    else:
        pValue += (ord('O')-ord('A')+1) * x

    pValue %= MOD
    x *= 27
    x %= MOD

sValue = 0 # 현재 체크중인 서브스트링의 해쉬값
x = 1
for i in range(n-1, -1, -1):
    sValue += (ord(s[i])-ord('A')+1) * x
    sValue %= MOD
    
    if i > 0:
        x *= 27
        x %= MOD
    
if sValue == pValue:
    answer += 1

for i in range(m-n):
    sValue -= (ord(s[i])-ord('A')+1) * x
    sValue *= 27
    sValue += (ord(s[i+n])-ord('A')+1)
    sValue %= MOD
    
    if sValue == pValue:
        answer += 1

print(answer)
