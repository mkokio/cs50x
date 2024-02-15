import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("You need exactly two command line arguments after the .py, dog.")
        return False

    # TODO: Read database file into a variable
    entries = []  # empty list
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        short_tandem_repeats = reader.fieldnames
        for entry in reader:
            entries.append(entry)

    # TODO: Read DNA sequence file into a variable
    sequence = ""
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    p = []
    for STR in short_tandem_repeats[1:]:
        p.append(longest_match(sequence, STR))
    profile = [str(i) for i in p]

    # TODO: Check database for matching profiles
    # short_tandem_repeats is this list ['name', 'AGATC', 'AATG', 'TATC']
    # entries is a list of dictionaries representing the database
    # sequence is the long string which we are looking up in the database
    # profile is a list of three strings ['4', '1', '5'] for example
    for entry in entries:
        profile_lookup = []
        for value in (entry.values()):
            profile_lookup.append(value)
        if profile_lookup[1:] == profile:
            print(profile_lookup[0])
            break
    else:
        print('No Match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
