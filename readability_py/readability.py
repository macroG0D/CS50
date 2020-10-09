from cs50 import get_string

# getting input
text = get_string("Enter the text: ")

letters = 0
sentences = 0
words = 1

# Checking for number of words, sentences and letters on text
for i in range(len(text)):
    if text[i] == " ":
        words += 1
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
    if text[i].isalpha():
        letters += 1

# assign the text parameters to the formula variables
W = 100 / words
L = letters * W
S = sentences * W

# the formula result
index = round(((0.0588 * L) - (0.296 * S)) - 15.8)

# output result
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
