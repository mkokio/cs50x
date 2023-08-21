#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main() {
    printf("Running the compiled binary...\n");
    string binary = "./sort1";
    system("%s", binary); // Replace "compiled_binary" with the actual binary name
    printf("Finished running the compiled binary.\n");

    return 0;
}
