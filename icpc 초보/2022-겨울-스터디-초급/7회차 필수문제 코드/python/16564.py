n, k = map(int, input().split())

x = []
for i in range(n):
    x.append(int(input()))

low = 0
high = 1000000000

while low + 1 < high:
    mid = (low + high) // 2
    temp = 0
    for i in range(n):
        temp += max(mid - x[i], 0)

    if k < temp:
        high = mid
    else:
        low = mid

print(low)