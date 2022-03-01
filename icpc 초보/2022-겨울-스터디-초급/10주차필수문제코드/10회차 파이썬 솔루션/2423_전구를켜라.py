from heapq import heappush, heappop
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

# 전체 정점의 개수, 사각형의 왼쪽 위에서부터 오른쪽으로 가면서 각 꼭지점을 정점으로 하여 0부터 번호를 매김
max_v = (n+1)*(m+1)
# 정의한 정점에 맞게 그래프 모델링
graph = [[] for _ in range(max_v)]
for i in range(n):
    line_list = input()
    v = (m+1)*i
    for j in range(m):
        if line_list[j] == '\\':
            graph[v].append((v+m+1+1, 0))  # v + (m+1) + 1, "v + (m+1)"은 아랫줄의 점
            graph[v+m+1+1].append((v, 0))
            graph[v+m+1].append((v+1, 1))
            graph[v+1].append((v+m+1, 1))
        else:
            graph[v].append((v+m+1+1, 1))
            graph[v+m+1+1].append((v, 1))
            graph[v+m+1].append((v+1, 0))
            graph[v+1].append((v+m+1, 0))
        v += 1

# 모델링한 그래프에 대해 다익스트라 수행
INF = float("inf")
visit = [False for _ in range(max_v)]
dist = [INF for _ in range(max_v)]
dist[0] = 0
pq = [(0, 0)]
while pq:
    d, now_v = heappop(pq)
    if visit[now_v]:
        continue

    visit[now_v] = True
    if now_v == max_v-1:
        print(dist[now_v])
        exit()

    for conn, d in graph[now_v]:
        distance = dist[now_v] + d
        if dist[conn] > distance:
            dist[conn] = distance
            heappush(pq, (distance, conn))

print("NO SOLUTION")