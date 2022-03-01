import sys
sys.setrecursionlimit(10**8)

def DFS(i, j, is_cow):
    global n
    for k in range(4):
        check_i = i + di[k]
        check_j = j + dj[k]
        if 0 <= check_i < n and 0 <= check_j < n:
            if not visit[check_i][check_j]:
                if board[i][j] == board[check_i][check_j]:
                    visit[check_i][check_j] = True
                    DFS(check_i, check_j, is_cow)
                elif is_cow and board[i][j] in ('R', 'G') and board[check_i][check_j] in ('R', 'G'):
                    visit[check_i][check_j] = True
                    DFS(check_i, check_j, is_cow)


n = int(input())
di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

board = [list(input()) for _ in range(n)]

# human
human_region = 0
visit = [[False for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visit[i][j]:
            human_region += 1
            DFS(i, j, is_cow=False)

# cow
cow_region = 0
visit = [[False for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visit[i][j]:
            cow_region += 1
            DFS(i, j, is_cow=True)

print(human_region, cow_region)