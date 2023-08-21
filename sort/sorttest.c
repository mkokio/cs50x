#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main() {
    printf("Running the compiled binary...\n");
    string time = "time";
    string binary = "./sort1";
    string filename = "random5000.txt";
    char command[50]; // Make sure the buffer is large enough

    // Create the command string
    snprintf(command, sizeof(command), "%s %s %s", time, binary, filename);

    system(command);
    printf("Finished running the compiled binary.\n");

    return 0;
}
