n = int(input())
p = list(map(int,input().split()))
p.sort()
ans = 0
for pi in p:
    ans += pi*n
    n -= 1
print(ans)