a, b, c = map(int, input().split())

result = 1
while b:
    if b % 2:
        result = (result * a) % c
    a = (a * a) % c
    b >>= 1

print(result)