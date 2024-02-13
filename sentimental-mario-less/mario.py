from cs50 import get_int

while True:
    number = get_int("Height: ")
    if 1 > number > 8:
        break

block = 1

while number > 0:
    print((" " * (number - 1)) + ("#" * (block)))
    number += -1
    block += 1

