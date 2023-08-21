#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <sys/wait.h>

int main() {
    //string binary = "./sort1";
    //string filename = "random5000.txt";
    //char command[100]; // Make sure the buffer is large enough

    // Create the command string
    //snprintf(command, sizeof(command), "time %s %s", binary, filename);
    //printf("%s",command);
    //string full_comand = (string) command;
    //system(command);
    printf("Running the compiled binary...\n");
    int result = system("time ./sort1 random5000.txt");

    if (result == -1) {
        perror("system");
    } else {
        int exitStatus = WEXITSTATUS(result);
        printf("Command exited with status: %d\n", exitStatus);
    }

    printf("Finished running the compiled binary.\n");

    return 0;    return 0;
}
