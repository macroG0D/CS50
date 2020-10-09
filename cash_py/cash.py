from cs50 import get_float

# ask for user input until gets the positive integer
while True:
    cash = get_float("Input your change owed: ")
    if cash >= 0:
        break

# converting cash to cents
cents = cash*100
# minimum number of coins for make change
coins = 0

while cents != 0:
    if cents >= 25:
        cents -= 25
        coins += 1
    elif cents >= 10:
        cents -= 10
        coins += 1
    elif cents >= 5:
        cents -= 5
        coins += 1
    else:
        cents -= 1
        coins += 1

print(coins)