# takes two argv — the databes.csv and the sequense txt, and identifies to whom the sequence belongs
import csv
import re
from sys import argv, exit

# check the correct number of arguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# read the sequence and remove the new line
with open(argv[2], 'r') as file:
    sequence = file.read().replace('\n', '')

STR = {
    'AGATC': 0,
    'AATG': 0,
    'TATC': 0
}


# check for longest sequences of the 3 STR and define the value to the variables
for i in range(len(sequence)):
    if re.findall("AGATC" * i, sequence):
        STR['AGATC'] = i
    else:
        break

for i in range(len(sequence)):
    if re.findall("AATG" * i, sequence):
        STR['AATG'] = i
    else:
        break

for i in range(len(sequence)):
    if re.findall("TATC" * i, sequence):
        STR['TATC'] = i
    else:
        break

# from 40 to 74 — check for additional keys that is only in the large database
for i in range(len(sequence)):
    if "TTTTTTCT" in sequence:
        if re.findall("TTTTTTCT" * i, sequence):
            STR['TTTTTTCT'] = i
        else:
            break

for i in range(len(sequence)):
    if "TCTAG" in sequence:
        if re.findall("TCTAG" * i, sequence):
            STR['TCTAG'] = i
        else:
            break

for i in range(len(sequence)):
    if "GATA" in sequence:
        if re.findall("GATA" * i, sequence):
            STR['GATA'] = i
        else:
            break

for i in range(len(sequence)):
    if "GAAA" in sequence:
        if re.findall("GAAA" * i, sequence):
            STR['GAAA'] = i
        else:
            break

for i in range(len(sequence)):
    if "TCTG" in sequence:
        if re.findall("TCTG" * i, sequence):
            STR['TCTG'] = i
        else:
            break


# open database csv as a dict and compare its values with the values of dict STR
with open(argv[1], 'r') as file:
    csv_file = csv.DictReader(file)
    for row in csv_file:
        a = int(dict(row)['AGATC'])
        b = STR['AGATC']
        c = int(dict(row)['AATG'])
        d = STR['AATG']
        e = int(dict(row)['TATC'])
        f = STR['TATC']
        # an additional keys from large database
        if "TTTTTTCT" in dict(row):
            g = int(dict(row)['TTTTTTCT'])
            h = STR['TTTTTTCT']
            i = int(dict(row)['TCTAG'])
            j = STR['TCTAG']
            k = int(dict(row)['GATA'])
            l = STR['GATA']
            m = int(dict(row)['GAAA'])
            n = STR['GAAA']
            o = int(dict(row)['TCTG'])
            p = STR['TCTG']

            if a == b and c == d and e == f and g == h and i == j and k == l and m == n and o == p:
                print(dict(row)['name'])
                exit(0)
        else:
            # else if found match print the name and exit, otherwise — print No match
            if a == b and c == d and e == f:
                print(dict(row)['name'])
                exit(0)

print("No match")