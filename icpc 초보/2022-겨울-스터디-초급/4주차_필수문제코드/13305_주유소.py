n = int(input())
dist = list(map(int, input().split()))
price = list(map(int, input().split()))
ans, minPrice = 0, float("inf")

for city in range(n-1):
    if price[city] < minPrice:
        minPrice = price[city]
    ans += minPrice*dist[city]
    
print(ans)