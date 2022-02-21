import sys

s = sys.stdin.readline().strip()

v = []
for i in range(len(s)):
    v.append(s[i:])

v.sort()
for i in range(len(v)):
    print(v[i])