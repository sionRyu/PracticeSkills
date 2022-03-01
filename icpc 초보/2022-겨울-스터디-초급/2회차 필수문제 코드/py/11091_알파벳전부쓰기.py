import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().rstrip().upper()
    isUsed = [False] * 26
    
    for c in s:
        if not c.isalpha():
            continue

        if not isUsed[ord(c) - ord('A')]:
            isUsed[ord(c) - ord('A')] = True

    l = []
    for i in range(26):
        if not isUsed[i]:
            l.append(chr(i + ord('a')))

    if l:
        print("missing", "".join(l))
    else:
        print("pangram")