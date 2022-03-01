import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

a.sort()
b.sort()

ans = 0
for i in range(len(a)):
    ans += a[i] * b[n - i - 1]

print(ans)