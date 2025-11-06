n, x = map(int, input().split(" "))

arr = list(map(int, input().split(" ")))

count = 0
i, j = 0, 0
ttl = arr[0]
while i < len(arr):
    if ttl > x:
        ttl -= arr[i]
        i+=1
    elif ttl == x:
        count += 1
        ttl -= arr[i]
        i+=1
        j+=1
        if j == len(arr):
            break
        ttl += arr[j]
    else:
        j+=1
        if j == len(arr):
            break
        ttl += arr[j]
print(count)