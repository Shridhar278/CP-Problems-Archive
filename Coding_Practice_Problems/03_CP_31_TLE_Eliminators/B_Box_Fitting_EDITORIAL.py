from math import log2


def solve_tc():
    n, w = list(map(int, input().split()))
    widths = list(map(int, input().split()))

    counts = [0 for _ in range(20)]

    for width in widths:
        counts[int(log2(width))] += 1

    space = w
    height = 1

    for it in range(n):
        largest = -1

        for size, count_width in list(enumerate(counts))[::-1]:
            if counts[size] > 0 and (2 ** size) <= space:
                largest = size
                break

        if largest == -1:
            space = w
            height += 1

            for size, count_width in list(enumerate(counts))[::-1]:
                if counts[size] > 0 and (2 ** size) <= space:
                    largest = size
                    break

        assert(largest != -1)
        counts[largest] -= 1
        space -= 2 ** largest

    print(height)


t = int(input())

while t > 0:
    t -= 1

    solve_tc()