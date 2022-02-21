n = int(input())
arr = [0 for _ in range(20000001)]

cards = list(map(int, input().split()))
for card in cards:
    arr[card + 10000000] += 1

m = int(input())

cards2 = list(map(int, input().split()))
for card in cards2:
    print(arr[card + 10000000], end = ' ')
