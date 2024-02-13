from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

coins = 0

types = [.25, .10, .05, .01]

while True:
    if change < 0:
        break
    for type in types:
        coins += int(change/type)
        print(f"quarters: {coins}")
        change = round(change - (coins*type),2)
        print(f"change: {change}")
