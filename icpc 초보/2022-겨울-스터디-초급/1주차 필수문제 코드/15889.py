import sys

n = int(input())
posList = list(map(int, sys.stdin.readline().split()))

if (n == 1):
    print("권병장님, 중대장님이 찾으십니다") 
else:
    rngList = list(map(int, sys.stdin.readline().split()))

    pos = posList[0]
    rng = rngList[0]

    for i in range(1, n - 1):
        gap = posList[i] - pos
        if gap <= rng and rng - gap < rngList[i]:
            pos = posList[i]
            rng = rngList[i]


    if posList[n - 1] <= pos + rng:
        print("권병장님, 중대장님이 찾으십니다") 
    else: 
        print("엄마 나 전역 늦어질 것 같아")