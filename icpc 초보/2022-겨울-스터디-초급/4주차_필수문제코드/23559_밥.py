import sys
input = sys.stdin.readline

n, x = map(int, input().split())
maxA = (x - 1000*n)//4000  # 최대 A 식사를 이용할 수 있는 횟수
l = []
for _ in range(n):
    l.append(tuple(map(int, input().split())))

l.sort(key=lambda x: x[0] - x[1], reverse=True)
answer = 0
for a, b in l:
    if maxA > 0 and a > b:  # A 식사를 이용할 수 있을 때, A식사의 맛의 값이 더 크면 A 식사 이용
        answer += a
        maxA -= 1
    else:
        answer += b
print(answer)