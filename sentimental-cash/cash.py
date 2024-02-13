from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

print(int(change/.25))
print(int(change/.10))
print(int(change/.05))
print(int(change/.01))
