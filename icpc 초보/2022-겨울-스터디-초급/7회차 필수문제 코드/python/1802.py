def solve(s):
    if len(s) == 1:
        return True
    for i in range(len(s) // 2):
        if int(s[i]) + int(s[len(s) - 1 - i]) != 1:
            return False

    return solve(s[ : len(s) // 2]) and solve(s[len(s) // 2 + 1: ])
t = int(input())

for tc in range(t):
    s = input()

    if (solve(s)):
        print("YES")
    else:
        print("NO")