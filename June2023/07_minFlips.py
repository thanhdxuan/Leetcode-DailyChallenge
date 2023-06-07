def minFlips(a: int, b: int, c: int) -> int:
    res = 0
    while a != 0 or b != 0 or c != 0:
        if c & 1 == 1:
            if a & 1 == 0 and b & 1 == 0:
                res += 1
        elif c & 1 == 0:
            res += ((a & 1) + (b & 1))
        a >>= 1
        b >>= 1
        c >>= 1
    return res
