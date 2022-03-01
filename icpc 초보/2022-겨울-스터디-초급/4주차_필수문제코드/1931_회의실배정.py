import sys
input = sys.stdin.readline

n = int(input())
meet = []
for _ in range(n):
    meet.append(tuple(map(int, input().split())))
meet.sort(key=lambda x: (x[1], x[0]))
fin, cnt = 0, 0
for m in meet:
    if m[0] >= fin:
        cnt+=1
        fin = m[1]
print(cnt)