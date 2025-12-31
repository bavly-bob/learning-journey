import csv
import sys


def main():
    # Check for correct usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # Read database file into a list of dictionaries
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        database = list(reader)

    # Get list of STRs (column names except 'name')
    str_sequences = reader.fieldnames[1:]

    # Read DNA sequence file into a string
    with open(sys.argv[2]) as file:
        sequence = file.read().strip()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for STR in str_sequences:
        str_counts[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    for person in database:
        match = True
        for STR in str_sequences:
            if int(person[STR]) != str_counts[STR]:
                match = False
                break
        if match:
            print(person["name"])
            return 0

    print("No match")
    return 0


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run


main()
