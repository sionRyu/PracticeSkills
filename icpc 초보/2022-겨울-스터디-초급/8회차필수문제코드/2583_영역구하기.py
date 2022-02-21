from collections import deque
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

n, m, k = map(int, input().split())
board = [[0 for _ in range(n)] for _ in range(m)]
for _ in range(k):
    start_x, start_y, end_x, end_y = map(int, input().split())
    for x in range(start_x, end_x):
        for y in range(start_y, end_y):
            board[x][y] = 1

visit = [[False for _ in range(n)] for _ in range(m)]
answer = []
for x in range(m):
    for y in range(n):
        if not visit[x][y] and board[x][y] == 0:
            size = 0
            # BFS
            d = deque()
            d.append((x, y))
            visit[x][y] = True
            size += 1
            
            while d:
                now_x, now_y = d.popleft()
                
                for k in range(4):
                    check_x = now_x + dx[k]
                    check_y = now_y + dy[k]
                    
                    if 0 <= check_x < m and 0 <= check_y < n:
                        if not visit[check_x][check_y] and board[check_x][check_y] == 0:
                            d.append((check_x, check_y))
                            visit[check_x][check_y] = True
                            size += 1

            answer. append(size)

print(len(answer))
for ans in sorted(answer):
    print(ans, end=' ')