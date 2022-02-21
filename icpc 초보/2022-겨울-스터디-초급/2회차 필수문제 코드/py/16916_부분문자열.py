import sys
input = sys.stdin.readline

s = input()
p = input()

if len(s) < len(p):
    print(0)
    exit()

MOD = 2**64
pValue = 0
x = 1
for i in range(len(p)-1, -1, -1):
    pValue += x*(ord(p[i])-ord('a')+1)
    pValue %= MOD
    x *= 27
    x %= MOD

sValue = 0
x = 1
for i in range(len(p)-1, -1, -1):
    sValue += x*(ord(s[i]) - ord('a') + 1)
    sValue %= MOD
    if i > 0:
        x *= 27
        x %= MOD

if sValue == pValue:
    print(1)
    exit()

for i in range(len(s) - len(p)):
    sValue -= (ord(s[i]) - ord('a') + 1)*x
    sValue *= 27
    sValue += (ord(s[i+len(p)]) - ord('a') + 1)
    sValue %= MOD
    if sValue == pValue:
        print(1)
        exit()

print(0)
