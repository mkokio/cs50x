from cs50 import get_int

while True:
    number = get_int("Height: ")
    if number > 9:
        break

block = 1

while number > 0:
    print((" " * (number - 1)) + ("#" * (block)))
    number += -1
    block += 1

