import cs50

print("O hai! ", end="")
while True:
    print("How much change is owed?")
    n = cs50.get_float()
    if n > 0:
        break

d = int(n * 100)
while d != 0:
    if d >= 25:
        s = int(d / 25)
        d = d % 25
    elif d >= 10 and d < 25:
        s += int(d / 10)
        d = d % 10
    elif d >= 5 and d < 10:
        s += int(d / 5)
        d = d % 5
    else:
        s += int(d)
        d = d % 1

print(s)