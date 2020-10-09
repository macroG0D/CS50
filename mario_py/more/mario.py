from cs50 import get_int

# check for input between 1 to 8 inclusive
while True:
    n = get_int("Height: ")
    if n in range(1, 9):
        break

for i in range(1, n + 1):
    if i != n:
        print(" " * (n - i - 1), "#" * i,  "", "#"*i)
    else:
        print("#" * i, "", "#"*i)


# submit50 cs50/problems/2020/x/sentimental/mario/more — gives 100%