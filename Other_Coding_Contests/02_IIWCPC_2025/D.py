#TOO complicated
n = int(input())
arr = [[] for i in range(n+1)]
arr[0] = [1]
while r2 != n:
    r1, r2 = map(int, input().split(" "))
    arr[r1].append(r2)
exp = 0
count = 1
while count != n or False:
    probs = 0
    new = arr
    exp += probs*count
    count += 1