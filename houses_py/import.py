# TODO
import cs50
import csv
from sys import argv, exit
# from cs50 import SQL

# check the correct number of arguments
if len(argv) != 2:
    print("Usage: python import.py file.csv")
    exit(1)

# Create empty students.db
open("students.db", "w").close

# Open that file for SQLite
db = cs50.SQL("sqlite:///students.db")

# Create table called students in database students.db
db.execute("CREATE TABLE students (id INTEGER PRIMARY KEY AUTOINCREMENT, first VARCHAR(255), middle VARCHAR(255), last VARCHAR(255), house VARCHAR(10), birth INTEGER)")

# Open csv file
with open(argv[1], "r") as students:

    # Create DictReader
    reader = csv.DictReader(students)

    for row in reader:

        house = row['house']
        birth = row['birth']

        # split name by words
        name = row['name'].split()

        first = name[0]
        last = name[1]

        # by default name don't have middle
        middle = None

        # if name has middle, change middle from None to name[1], and last from name[1] to name[2]
        if len(name) == 3:
            middle = name[1]
            last = name[2]

        # Insert student in table
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)