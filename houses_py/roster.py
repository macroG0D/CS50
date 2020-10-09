# TODO
import cs50
import csv
from sys import argv, exit
# from cs50 import SQL

# check the correct number of arguments
if len(argv) != 2:
    print("Usage: python roster.py house")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

test = db.execute('SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last', argv[1])

# db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
#     first, middle, last, house, birth)

for row in test:
    first = row['first']
    last = row['last']
    birth = row['birth']
    if row['middle'] != None:
        middle = row['middle']
        print(f"{first} {middle} {last}, born {birth}")
    else:
        print(f"{first} {last}, born {birth}")


# print(test)