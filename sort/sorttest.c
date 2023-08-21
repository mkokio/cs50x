#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main() {
    printf("Running the compiled binary...\n");
    string filename = "random5000.txt";
    system("./sort1 %s", filename);
    printf("Finished running the compiled binary.\n");

    return 0;
}
