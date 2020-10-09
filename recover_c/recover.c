#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) // checking for the right input and return error if it is not
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *cardfile = fopen(argv[1], "r");
    if (cardfile == NULL)
    {
        printf("Can't open the file\n");
        return 1;
    }

    BYTE *buffer = malloc(sizeof(BYTE) * 512);
    char filename[9];
    FILE *recovered;
    int count = 0;

    while (fread(buffer, sizeof(BYTE), 512, cardfile) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // if it is a start of a jpg file
        {
            if (count == 0) // if this is the first found image, then just open a new jpg file
            {
                sprintf(filename, "%03i.jpg", count);
                recovered = fopen(filename, "w");
                count++;
            }
            else if (count > 0) // if it is not a first image, then close the previosly opened jpg file and open a new one
            {
                fclose(recovered);
                sprintf(filename, "%03i.jpg", count);
                recovered = fopen(filename, "w");
                count++;
            }
        }  // if it is not a start of jpg file, keep writing
        fwrite(buffer, sizeof(BYTE), 512, recovered);
    }

    fclose(recovered);
    fclose(cardfile);
    free(buffer);

    // printf("Total images found: %i\n", count); // check for a number of found images

}
