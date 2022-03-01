from collections import deque

start, find = map(int, input().split())
visit = dict()
d = deque()
d.append((start, 1))
while d:
    now, count = d.popleft()

    if now > find:
        continue

    if now == find:
        print(count)
        exit(0) # 프로그램 종료

    # 키 에러를 이용해 visit 체크
    try:
        t = visit[now*2]
    except:
        visit[now*2] = 0
        d.append((now*2, count + 1))

    try:
        t = visit[now*10 + 1]
    except:
        visit[now*10 + 1] = 0
        d.append((now*10 + 1, count + 1))


# count 출력을 못한 경우
print(-1)