# pypy로 제출
from bisect import bisect_left

n = int(input())
pos = [0 for _ in range(10001)]
arr = []

for i in range(n):
    pos[i] = list(map(int, input().split()))
    arr.append(pos[i][0])
    arr.append(pos[i][1])

arr = list(set(arr))
arr.sort()

for i in range(n):
    pos[i][0] = 1 + bisect_left(arr, pos[i][0])
    pos[i][1] = 1 + bisect_left(arr, pos[i][1])

wall = [0 for _ in range(10000001)]
for i in range(n):
    for j in range(pos[i][0], pos[i][1] + 1):
        wall[j] = i + 1


ans = 0
chk = [False for _ in range(50001)]
for i in range(30001):
    if 0 < wall[i] and chk[wall[i]] == False:
        chk[wall[i]] = True
        ans += 1

print(ans)

