def DFS(com):
    global answer
    for conn in graph[com]:
        if not visit[conn]:
            visit[conn] = True
            answer += 1
            DFS(conn)

computer = int(input())
n = int(input())
graph = [[] for _ in range(computer+1)] # 1부터 인덱스를 잡기 위해 computer+1 로 설정
visit = [False for _ in range(computer+1)]
for _ in range(n):
    com1, com2 = map(int, input().split())
    graph[com1].append(com2)
    graph[com2].append(com1)

answer = 0
visit[1] = True
DFS(1)

print(answer)