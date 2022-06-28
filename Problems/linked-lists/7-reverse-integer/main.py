def reverse(x):
    res = 0
    l = len(str(abs(x)))
    while x != 0:
        res += (x % 10) * (10 ** (l - 1))
        x //= 10
        l -= 1
    return res


print(-1//10)
print(reverse(-123))
