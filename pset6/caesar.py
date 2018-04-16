import cs50
import sys

b = []
if len(sys.argv) != 2:
    print("Usage: {} k".format(sys.argv[0]))

k = int(sys.argv[1])
e = k % 26
a = cs50.get_string("plaintext: ")
print("ciphertext: ", end="")
for i in range(0, len(a)):
    if a[i].isalpha() == True:
        if a[i] >= 'a' and a[i] <= 'z':
            b.append(chr(ord(a[i]) + e))
            if ord(b[i]) > 122:
                d = ord(b[i]) - 122
                b[i] = 97 + d - 1
            print("%c" %(b[i]), end="")
        if a[i] >= 'A' and a[i] <= 'Z':
            b.append(chr(ord(a[i]) + e))
            if ord(b[i]) > 90:
                d = ord(b[i]) - 90
                b[i] = 65 + d - 1
            print("%c" %(b[i]), end="")
    else:
        print("{}".format(chr(b[i]), end=""))
print()