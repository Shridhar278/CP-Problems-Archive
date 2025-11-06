# B87678

import math

# calculate S(n), then get E(n)= S(n)-S(n-1)
# S(n)= summation from E(0) to E(n)

# Sn = [0]

# def calc_Sn(n, k):
#     if k <= n:
#         old = len(Sn)-1
#         Sn.append((1+1/(old+1))*Sn[old]+1)
#     else:
#         return
#     return calc_Sn(n, k+1)

# def prompt():
#     for _ in range(int(input())):
#         n = int(input())
#         if len(Sn) > n:
#             print(math.floor(Sn[n]-Sn[n-1]))
#         else:
#             calc_Sn(n, len(Sn))
#             print(math.floor(Sn[n]-Sn[n-1]))

# prompt()

# SHORTER

sums = [0]

def calc_sum(n):
    k = len(sums)
    for i in range(k, n+1):
        sums.append(sums[len(sums)-1]+1/(i+1))

def new():
    for _ in range(int(input())):
        n = int(input())
        if len(sums) > n:
            a = sums[n]*(n+1)-sums[n-1]*(n)
            print(math.floor(a))
        else:
            calc_sum(n)
            a = sums[n]*(n+1)-sums[n-1]*(n)
            print(math.floor(a))

new()