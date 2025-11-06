# NOT OPTIMIZED

input()
for _ in range(int(input())):
    d = int(input())
    if d ==1:
        print(0, 0)
        continue
    p = 2
    ans1, ans2 = 0, 1
    while d!=1:
        if d % p == 0:
            c = 0
            while d % p == 0:
                c+=1
                d /=p
            ans2*=c+1
            ans1+=c
        if p %2:
            p+=1
        p+=1
    if ans2 % 2 == 1:
        ans2 = ans2//2+1
    else:
        ans2 = ans2//2
    print(ans1, ans2)