import sys
import numpy as np

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = np.array(list(map(int, input().split())), dtype=np.int64)

    freq = np.bincount(a, minlength=m + 1)

    suffix = np.cumsum(freq[::-1])[::-1]

    double_count = np.zeros(m + 1, dtype=np.int64)
    double_count[:m // 2 + 1] = freq[::2][:m // 2 + 1]

    ans = suffix + double_count

    print(int(ans[1:].max()))