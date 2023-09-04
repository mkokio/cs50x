#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // look for a candidate called 'name'
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // update preferences so they are the voter's rank prefence
            preferences[voter][rank] = i;
            printf("The voter %i has set %s as rank %i.\n", voter, name, rank);
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
//The function should update the number of votes each candidate has at this stage in the runoff.
//Recall that at each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.
//Recall that voter_count stores the number of voters in the election and that, for each voter in our election, we want to count one ballot.
//Recall that for a voter i, their top choice candidate is represented by preferences[i][0], their second choice candidate by preferences[i][1], etc.
//Recall that the candidate struct has a field called eliminated, which will be true if the candidate has been eliminated from the election.
//Recall that the candidate struct has a field called votes, which you’ll likely want to update for each voter’s preferred candidate.
//Once you’ve cast a vote for a voter’s first non-eliminated candidate, you’ll want to stop there, not continue down their ballot! Recall that you can break out of a loop early using break inside of a conditional.


    //loop each voter's ballots
    for (int voter = 0; voter < voter_count; voter++)
    {
        //look for eliminated FALSE candidate in 0 position
        int rank = 0;
        while (candidates[preferences[voter][rank]].eliminated) // if false (as in, not eliminated)
            {
                rank++;
            }
        candidates[preferences[voter][rank]].votes++;
        printf("Candidate: %s has %i votes.\n", candidates[preferences[voter][rank]].name, candidates[preferences[voter][rank]].votes);
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // If any candidate has more than half of the vote, their name should be printed and the function should return true.
    //If nobody has won the election yet, the function should return false.

    //set necessary majority
    float majority = voter_count/2;
    //loop through candidate's scores
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO

    //The function should return the minimum vote total for any candidate who is still in the election.
    //You’ll likely want to loop through the candidates to find the one who is both still in the election
    //and has the fewest number of votes. What information should you keep track of as you loop through the candidates?
    // if ALL non-eliminated candidates have the "min" votes the function should return true.
    //For i from 0 to n-1
        //Find smallest number between numbers[i] and numbers[n-1]
        //Swap smallest number with numbers[i]

    for (int i = 0; i < candidate_count; i++)
    {
        int fewest_votes = voter_count;
        while (!candidates[i].eliminated) //while FALSE (as in, NOT eliminated)
        {

        }
    }

    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}