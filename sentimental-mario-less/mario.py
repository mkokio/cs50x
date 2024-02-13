from cs50 import get_int

while True:
    number = get_int("Height: ")
    if number < 9:
        break

while number > 0:
    print(" " * (number - 1) + "#" * )
    number += -1

