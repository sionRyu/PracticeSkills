import sys

n = int(sys.stdin.readline())
x = list(map(int, sys.stdin.readline().split()))
y = sorted(list(set(x)))

dic = {}
for i in range(len(y)):
    dic[y[i]] = i

for i in range(n):
    print(dic[x[i]], end=" ")