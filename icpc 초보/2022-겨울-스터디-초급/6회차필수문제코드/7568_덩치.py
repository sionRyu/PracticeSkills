n = int(input())
l = []
for _ in range(n):
    x, y = map(int, input().split())
    l.append((x, y))

answer = []
for i in range(n):
    x, y = l[i][0], l[i][1]
    grade = 1
    for j in range(n):
        if j == i:
            continue
        
        if x < l[j][0] and y < l[j][1]:
            grade += 1
    
    answer.append(grade)

for i in range(n):
    print(answer[i], end=' ')