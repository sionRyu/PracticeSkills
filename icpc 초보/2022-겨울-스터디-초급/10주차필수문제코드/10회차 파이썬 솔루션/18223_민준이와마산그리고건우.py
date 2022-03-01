from heapq import heappush, heappop
import sys
input = sys.stdin.readline

def dijkstra(s, e): # s ~ e 까지 최단 거리를 반환, 도달할 수 없으면 float("inf") 반환
    global v, graph
    INF = float("inf")
    visit = [False for _ in range(v+1)]
    dist = [INF for _ in range(v+1)]
    dist[s] = 0
    pq = [(0, s)]
    while pq:
        d, now_v = heappop(pq)
        
        if visit[now_v]:
            continue
        visit[now_v] = True
        
        if now_v == e:
            return dist[now_v]

        for conn, d in graph[now_v]:
            distance = dist[now_v] + d
            if dist[conn] > distance:
                dist[conn] = distance
                heappush(pq, (distance, conn))

    return float("inf")


v, e, p = map(int, input().split())
graph = [[] for _ in range(v+1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

s_to_p = dijkstra(1, p) # 1~p
p_to_e = dijkstra(p, v) # p~v
s_to_e = dijkstra(1, v) # 1~v

if s_to_p + p_to_e == s_to_e:
    print("SAVE HIM")
else:
    print("GOOD BYE")