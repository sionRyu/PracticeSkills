from heapq import heappush, heappop
import sys
input = sys.stdin.readline
INF = float("inf")

T = int(input())
for testcase in range(1, T+1):
    n, m = map(int, input().split())
    graph = [[] for _ in range(m)]
    visit = [False for _ in range(m)]
    prev = [-1 for _ in range(m)]
    dist = [INF for _ in range(m)]

    for _ in range(n):
        p1, p2, r = map(int, input().split())
        graph[p1].append((p2, r))
        graph[p2].append((p1, r))

    pq = []
    heappush(pq, (0, 0))
    dist[0] = 0
    while pq:
        relation_cost_sum, person = heappop(pq)

        if visit[person]:
            continue
        
        visit[person] = True

        for conn, relation in graph[person]:
            relation_cost = relation_cost_sum + relation
            if relation_cost < dist[conn]:
                dist[conn] = relation_cost
                heappush(pq, (relation_cost, conn))
                prev[conn] = person

    answer = []
    track = m-1
    while track != -1:
        answer.append(track)
        track = prev[track]

    answer = list(reversed(answer))

    print(f"Case #{testcase}: ", end='')
    if answer[0] == 0 and answer[-1] == m-1:
        print(*answer) # answer 리스트의 내용을 띄어쓰기를 주며 출력 (언패킹 출력)
    else:
        print(-1)