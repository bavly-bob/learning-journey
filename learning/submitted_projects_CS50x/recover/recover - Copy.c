#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;   // pointer to current JPEG file
    char filename[8];   // "###.jpg"
    int file_count = 0; // number of JPEGs found

    // Read blocks until EOF
    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        // Check for JPEG signature
        int is_jpeg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
                      (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg)
        {
            // If already writing to a file, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new filename
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "wb");
            file_count++;
        }

        // If we have started a JPEG, write the block
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close any remaining file
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(infile);
    return 0;
}
