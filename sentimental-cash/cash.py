from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

coins = 0

coins += int(change/.25)
change = change - (int(change/.25)*.25)
print(coins)
print(change)
coins += int(change/.10)
change = clearchange - (int(change/.10)*.10)
print(coins)
print(change)
coins += int(change/.05)
change = change - (int(change/.05)*.05)
print(coins)
print(change)
coins += int(change/.01)
change += change - (int(change/.01)*.01)


print(coins)
