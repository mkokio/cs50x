from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

quarters = 0
dimes = 0
quarters += int(change/.25)
print(f"quarters: {quarters}")
print(f"change: {change}")
print(quarters*.25)
print(f"Remaining money after quarters: {round(change - (quarters*.25),2)}")

quarters += int(change/.25)
print(f"dimes: {dimes}")
print(f"change: {change}")
print(dimes*.10)
print(f"Remaining money after quarters: {round(change - (dimes*.10),2)}")
