def BackTracking(idx, v):
    global n, s, count
    if v + nums[idx] == s:
        count += 1

    if idx < n-1:
        BackTracking(idx+1, v+nums[idx])
        BackTracking(idx+1, v)


n, s = map(int, input().split())
nums = list(map(int, input().split()))
count = 0
BackTracking(0, 0)
print(count)