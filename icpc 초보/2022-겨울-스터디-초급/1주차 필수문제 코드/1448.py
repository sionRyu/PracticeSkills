import sys

n = int(sys.stdin.readline())

l = [0 for i in range(n)]
for i in range(n):
    l[i] = int(sys.stdin.readline())

l.sort(reverse=True)

ans = -1
for i in range(n - 2):
    if l[i] < l[i + 1] + l[i + 2]:
        ans = l[i + 2] + l[i + 1] + l[i]
        break

print(ans)