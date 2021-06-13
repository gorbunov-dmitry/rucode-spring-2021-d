from math import gcd
from random import randint

def f(x, n):
    return (x**2 + 1) % n

def find_simple(n):
    p = 2
    while p**2 <= n:
        if not n % p:
            return p
        p += 1
    return 1

def find_rho(n):
    x = randint(1, n-2)
    y = x
    counter = int(n**(1/4)) * 3
    while abs(gcd(n, x-y)) in [1, n] and counter > 0:
        x = f(f(x, n), n)
        y = f(y, n)
        counter -= 1
    return abs(gcd(n, x-y))

n = int(input())

if n < 10**9:
    ans = find_simple(n)
else:
    ans = find_rho(n)

if abs(ans) in [1, n]:
    print('IMPOSSIBLE')
else:
    ans = abs(ans)
    print(ans, n // ans)
