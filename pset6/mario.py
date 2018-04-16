import cs50

while True:
    print("Height : ")
    h = cs50.get_int()
    if h > 0 and h < 23:
        break

for i in range(0, h):
    for j in range(h-i-1, 0, -1):
        print(" ", end="")
    for k in range(0, i+1):
        print("#", end="")
    print("  ", end="")
    for l in range(0, i+1):
        print("#", end="")
    print("\n")