# B87678

fibo = [1, 1]

def fibonacci(n):
    fibo.append(fibo[len(fibo)-1]+fibo[len(fibo)-2])
    if len(fibo) == n:
        return
    fibonacci(n)

def givebinarygaps(n):
    gap = []
    count = 0
    top = 0
    while n >= 1:
        if n % 2 == 1:
            gap.append(count)
            count = 0
        else:
            count += 1
        n = n // 2
        top += 1
    return gap, top

def howmany3(case):
    n3 = 0
    while case != 1:
        if case % 3 == 0:
            n3 += 1
            case = case // 3
        else:
            return case, n3
    return case, n3

def prompt():
    for _ in range(int(input())):
        n = (int(input()) - 1)//2
        gaps, tops = givebinarygaps(n)
        pq = tops
        cases = 1
        for gp in gaps:
            if len(fibo) <= gp:
                fibonacci(gp+1)
            cases *= fibo[gp]
        cases, x = howmany3(cases)
        pq -= x
        pq += cases
        pq = pq % (10**9 + 7)
        print(pq)

prompt()