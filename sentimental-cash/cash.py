from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

coins = 0

coins += int(change/.25)
print(f"quarters: {coins}")
change = change - (int(change/.25)*.25)
coins += int(change/.10)
print(f"dimes: {coins}")
change = change - (int(change/.10)*.10)
coins += int(change/.05)
change = change - (int(change/.05)*.05)
coins += int(change/.01)
change = change - (int(change/.01)*.25)

print(coins)
