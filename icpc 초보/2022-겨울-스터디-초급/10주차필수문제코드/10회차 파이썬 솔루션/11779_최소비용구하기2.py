from heapq import heappop, heappush
import sys
input = sys.stdin.readline
INF = float("inf")

n = int(input())
graph = [[] for _ in range(n+1)]
dist = [INF for _ in range(n+1)]
visit = [False for _ in range(n+1)]
prev = [-1 for _ in range(n+1)]

m = int(input())
for _ in range(m):
    s, e, t = map(int, input().split())
    graph[s].append((e, t))

start, end = map(int, input().split())

dist[start] = 0
pq = []
heappush(pq, (0, start)) # (dist, city)
while pq:
    now_dist, now_city = heappop(pq)

    if not visit[now_city]:
        visit[now_city] = True
    else:
        continue

    for conn, conn_dist in graph[now_city]:
        if now_dist + conn_dist < dist[conn]:
            dist[conn] = now_dist + conn_dist
            prev[conn] = now_city
            heappush(pq, (dist[conn], conn))

path = []
track = end
while track != -1:
    path.append(track)
    track = prev[track]

print(dist[end])
print(len(path))
for seq in reversed(path):
    print(seq, end=' ')