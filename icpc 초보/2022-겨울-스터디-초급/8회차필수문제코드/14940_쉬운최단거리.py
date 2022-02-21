from collections import deque
import sys
input = sys.stdin.readline

di = [0, 0, -1, 1]
dj = [1, -1, 0, 0]

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visit = [[False for _ in range(m)] for _ in range(n)]
distance = [[0 for _ in range(m)] for _ in range(n)]

d = deque()
for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            d.append((i, j, 0))

while d:
    i, j, dist = d.popleft()

    for k in range(4):
        check_i = i + di[k]
        check_j = j + dj[k]
        if 0 <= check_i < n and 0 <= check_j < m:
            if board[check_i][check_j] == 1 and not visit[check_i][check_j]:
                visit[check_i][check_j] = True
                distance[check_i][check_j] = dist+1
                d.append((check_i, check_j, dist+1))

# 갈 수 있는데 방문 못한 곳 -1 표시
for i in range(n):
    for j in range(m):
        if distance[i][j] == 0 and board[i][j] == 1:
            distance[i][j] = -1

# 출력
for i in range(n):
    for j in range(m):
        print(distance[i][j], end=' ')
    print()