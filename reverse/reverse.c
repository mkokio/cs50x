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
    int endofheaderposition = ftell(ptr1); //44 btw
    printf("%i\n", endofheaderposition);

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
// fseek: sets a file pointer to a given offset. It may be useful to experiment with negative offset
// values to move a file pointer backwards.
// ftell: returns the current position of a file pointer.
// It may be useful to inspect what value ftell returns after the input header is
// read in the third TODO in addition to what it returns while the audio data is being read.
// Keep in mind that after you use fread to load in a block of data, the input pointer will
// be pointing at the location where the read concluded. In other words, the input pointer
// may need to be moved back two block sizes after each fread, one to move back to where
// the fread began, and the second to move to the previous, unread block.

// use fseek to move the file pointer to the ith position in ptr1, then
// use fgetc to read the character at that position. After that, you'll want to
// write that character to the corresponding position in ptr2.
// Remember to also move the file pointer in ptr2 to the correct position before writing.
// You can calculate the correct position in ptr2 based on i, endoffileposition, and endofheaderposition.

    fseek(ptr1, 0, SEEK_END); //offest is zero from the end of the file
    int endoffileposition = ftell(ptr1);
    for (int i = endoffileposition - 1; i >= endofheaderposition; i--)
    {
        //copy (write) the last character of ptr1 into the first position of ptr2
        fseek(ptr1, i, SEEK_SET); // move to the ith position (one less each loop)
        char ch = fgetc(ptr1); // read and store that character as ch
        
        fputc(ch, ptr2); // put that character in place
    }

fclose(ptr1);
fclose(ptr2);
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


int get_block_size(WAVHEADER header) //bytes per sample X number of channels. represents the size of the data
{
    // TODO #7
    int block_size = header.numChannels * (header.bitsPerSample / 8);
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
