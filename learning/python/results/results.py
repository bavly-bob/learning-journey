# project/results.py
# Analyze results from a CSV file and print the distribution of percentages.
# The CSV file is expected to have a "total_degree" column.
# Scores above 320 are ignored.
# The percentages are calculated as (score / 320) * 100 and rounded to the nearest integer.
# The output lists each percentage and its count in ascending order.
# This databse was the entir country's results for a certain exams for over a 800,000 student.
import csv
from collections import Counter

with open("results.csv", "r", encoding="cp1256") as file:
    results = csv.DictReader(file, delimiter=";")

    percentages = []
    for row in results:
        score = float(row["total_degree"].strip())

        if score <= 320:  # ignore scores above 320
            percent = round((score / 320) * 100)  # round to nearest %
            percentages.append(percent)

    counts = Counter(percentages)

for percent, count in sorted(counts.items()):
    print(f"{percent}% : {count}")
