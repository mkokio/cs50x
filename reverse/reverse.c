#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    char *input = argv[1];
    FILE* ptr1 = fopen(input, "r"); // don't forget to close the program later

    // Read header
    // TODO #3
    WAVHEADER headercopy;
    fread(&headercopy, sizeof(WAVHEADER), 1, ptr);

    // Use check_format to ensure WAV format
    // TODO #4

    // Open output file for writing
    // TODO #5
    char *output = argv[2];
    FILE* ptr2 = fopen(output, "w")

    // Write header to file
    // TODO #6
    fwrite()

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    //if () // it is a wav file
    {
        return 0;
    }
    //else // it is NOT a wav file
    {
    //    printf("Input is not a WAV file.\n");
    //    return 1;
    }
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}