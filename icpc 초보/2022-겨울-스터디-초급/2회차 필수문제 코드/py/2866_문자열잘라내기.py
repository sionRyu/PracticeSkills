import sys
input = sys.stdin.readline
MOD = 2**64

r, c = map(int, input().split())
sList = []
sValueMatrix = [[0 for _ in range(c)] for _ in range(r)] # 각 접미사배열의 해쉬값 리스트
for _ in range(r):
    sList.append(list(input().rstrip()))

for j in range(c):
    x = 27
    sValueMatrix[r-1][j] = ord(sList[r-1][j]) - ord('a') + 1
    for i in range(r-2, -1, -1):
        sValueMatrix[i][j] = sValueMatrix[i+1][j] + (ord(sList[i][j]) - ord('a') + 1)*x
        x *= 27
        x %= MOD

cnt = 0
fin = False
for i in range(1, r):
    d = dict()
    for j in range(c):
        t = sValueMatrix[i][j]
        # 딕셔너리 에러를 이용한 중복값 체크
        try:
            if d[t]:
                fin = True
                break
        except:
            d[t] = 1
            
    if fin:
        break
        
    cnt += 1
    
print(cnt)