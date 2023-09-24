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
    fread(&headercopy, sizeof(WAVHEADER), 1, ptr1);

    // Use check_format to ensure WAV format
    // TODO #4
    check_format(headercopy);

    // Open output file for writing
    // TODO #5
    char *output = argv[2];
    FILE* ptr2 = fopen(output, "w");

    // Write header to file
    // TODO #6
    fwrite(&headercopy, sizeof(WAVHEADER), 1, ptr2);

    // Use get_block_size to calculate size of block
    // TODO #7
    get_block_size(headercopy);

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char *wave = "WAVE";
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != wave[i])
        {
            printf("Input is not a WAV file.\n");
            return 1;
        }
    }
    return 0;
}


int get_block_size(WAVHEADER header) //bytes per sample X number of channels
{
    // TODO #7
    int block_size = header.numChannels * (int) header.sampleRate / (int) header.byteRate;
    printf("%i\n", block_size);
    return block_size;
}
// return an integer representing the block size of the given WAV file,
// in bytes. We can think of a block as a unit of auditory data. For audio,
// we calculate the size of each block with the following calculation:
// number of channels multiplied by bytes per sample. Luckily, the header
// contains all the information we need to compute these values.
// Be sure to reference the Background section for a more in-depth explanation
// as to what these values mean and how they are stored. See too wav.h, to determine which members of WAVHEADER might be useful.
// Notice that one of the members of WAVHEADER is bitsPerSample. But to calculate block size, you’ll need bytes per sample!
