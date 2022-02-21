def isPalindrome(p):
    p = str(p)
    for i in range(len(p)//2):
        if p[i] != p[len(p)-1-i]:
            return False
    return True

isPrime = [True for _ in range(2000000)]
PrimeList = []
for i in range(2, 2000000):
    if isPrime[i]:
        for j in range(i+i, 2000000, i):
            isPrime[j] = False
        PrimeList.append(i)

n = int(input())
for p in PrimeList:
    if p >= n and isPalindrome(p):
        print(p)
        break