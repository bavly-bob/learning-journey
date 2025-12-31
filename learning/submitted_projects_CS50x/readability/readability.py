s = input("text: ")

word_count = 1
letters_count = 0
sentence_count = 0


for ch in s:
    if ch.isalpha(): #letter count
        letters_count += 1
    elif ch == ' ': #words count assuming no double spaces
        word_count += 1
    elif ch in ['!', '?', '.']: #setence count
        sentence_count += 1

# Coleman–Liau formula
L = (letters_count / word_count) * 100
S = (sentence_count / word_count) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print result
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
