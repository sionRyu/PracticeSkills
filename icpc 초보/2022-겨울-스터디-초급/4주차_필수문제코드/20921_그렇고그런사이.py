n, k = map(int, input().split())
answer = []
use = [False for _ in range(n+1)]
use[0] = True
now = n
while k:
    if now-1 <= k:
        k -= (now-1)
        use[now] = True
        answer.append(now)
    now -= 1

for i in range(1, n+1):
    if not use[i]:
        answer.append(i)

for i in range(n):
    print(answer[i], end=' ')