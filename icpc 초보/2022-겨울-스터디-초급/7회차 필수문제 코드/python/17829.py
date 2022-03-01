def solve(y, x, n):
    if n == 1:
        return arr[y][x]

    v = []
    v.append(solve(y, x, n // 2))
    v.append(solve(y + n // 2, x, n // 2))
    v.append(solve(y, x + n // 2, n // 2))
    v.append(solve(y + n // 2, x + n // 2, n // 2))
    v.sort()

    return v[2]

n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

print(solve(0, 0, n))