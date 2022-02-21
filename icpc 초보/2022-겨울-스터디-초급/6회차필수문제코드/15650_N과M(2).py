def f(size, t):
    global n, m
    if len(t) == m:
        print(*t) # 튜플을 언패킹해서 출력
        return
  
    for i in range(1, n+1):
        if t and i <= t[-1]:
            continue
        f(size+1, t + (i,))

n, m = map(int, input().split())
f(0, tuple())