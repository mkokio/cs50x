#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) // copies command-line arguments into the array candidates... available globally?
    {
        candidates[i].name = argv[i + 1]; // because argv[i] is ./plurality
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++) // let every voter type in a vote
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // search if 'name' is in candidates.name[0 to argc-1]
    for (int i = 0; i < candidate_count; i++)
    {
        // repeat until end, starting at first element THIS IS LINEAR SEARCH
        if (strcmp(candidates[i].name, name) == 0)
        {
            // if first element is 'name', stop and add vote
            candidates[i].votes++;
            return true;
        }
    }
    // if 'name' is not in argv[], return false (an invalid vote)
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // The function should print out the name of the candidate who received
    // the most votes in the election, and then print a newline.
    // It is possible that the election could end in a tie if multiple
    // candidates each have the maximum number of votes. In that case,
    // you should output the names of each of the winning candidates, each on a separate line.
    // (doing practice MAX before this part)
    // set current max
    int max = 0;
    // iterate through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // check if element is bigger than current max, if so, make current max
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    // iterate through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}