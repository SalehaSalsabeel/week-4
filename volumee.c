#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
     {
      if (argc != 4)
      {
     printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

       FILE *input = fopen(argv[1], "rb");
       FILE *output = fopen(argv[2], "wb");
     float factor = atof(argv[3]);

     uint8_t header[44];
    fread(header, 1, 44, input);
    fwrite(header, 1, 44, output);

      int16_t sample;
    while (fread(&sample, sizeof(int16_t), 1, input))
       {
        sample *= factor;
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

      fclose(input);
      fclose(output);
    return 0;
}
