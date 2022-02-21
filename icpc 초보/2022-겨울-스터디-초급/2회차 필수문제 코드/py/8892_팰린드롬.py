import sys
input = sys.stdin.readline

def isPalindrome(s):
    l = len(s)
    for i in range(l//2):
        if s[i] != s[l-1-i]:
            return False
            
    return True

T = int(input())
for _ in range(T):
    n = int(input())
    sList = []
    for _ in range(n):
        sList.append(input().rstrip())

    isFound = False
    for i in range(n):
        now_s = sList[i]
        for j in range(n):
            if j == i:
                continue
            if isPalindrome(now_s + sList[j]):
                print(now_s + sList[j])
                isFound = True
                break

        if isFound:
            break

    if not isFound:
        print(0)