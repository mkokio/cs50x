from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

quarters = 0
quarters += int(change/.25)
print(f"quarters: {quarters}")
print(f"change: {change}")
print(quarters*.25)
print(f"Remaining money after quarters: {change - (quarters*.25)}")

