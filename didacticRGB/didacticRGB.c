/*Challenge 'Didactic RGB' [Crypto]
Do you see the single-color image below?

This image is actually only 1 pixel by 1 pixel, and is stretched out here so you
can see it. What can such an image represent? Pixels are commonly composed on a
computer of red, green, and blue components. Each component can be any number of
bits -- the more bits, the more detail an image can reflect. A common number of bits
per color is eight. If we look at this single pixel, we get three colors of eight bits
each, which equals 24 bits of data total. What to do with those 24 bits? For this
challenge, express it as a decimal integer. That is your answer. (In other words,
the answer looks something like '12345678'. These are all 24 bits considered as one
single number in decimal.) */

#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include <errno.h>
#include <string.h>

int width, height;
png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers;

//Function to check if the file passed to the program is a PNG image
int checkIfPng(char *filename)
{
    //Open Image File
    FILE *fp = fopen(filename, "rb");

    //Handle error File
    if(!fp||errno)
    {
        perror("ERROR");
        return EXIT_FAILURE;
    }

    //Check if the file is an PNG image
    char header[9]; //we need to store 8 byes + \0
    fread(header, 1 ,8, fp); //Read only 8 bytes of the beginning of the file
    int isPng = png_sig_cmp((const unsigned char*)header, 0, 8); //Compare if the signature "PNG" was founded, 0 founded

    if (isPng)
    {
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

//Read PNG file information
int readPngFile(char *filename)
{
    //Open Image File
    FILE *fp = fopen(filename, "rb");

    //Handle error File
    if(!fp||errno)
    {
        perror("ERROR");
    }

    //Create png structture
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if(!png)
        return EXIT_FAILURE;

    png_infop info = png_create_info_struct(png);

    if(!info)

    if(setjmp(png_jmpbuf(png)))
        return EXIT_FAILURE;

    png_init_io(png, fp);

    png_read_info(png, info);

    width      = png_get_image_width(png, info);
    height     = png_get_image_height(png, info);
    color_type = png_get_color_type(png, info);
    bit_depth  = png_get_bit_depth(png, info);

    // Read any color_type into 8bit depth, RGBA format.
    // See http://www.libpng.org/pub/png/libpng-manual.txt

    if(bit_depth == 16)
        png_set_strip_16(png);

    if(color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
    if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    if(png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);

    // These color_type don't have an alpha channel then fill it with 0xff.
    if(color_type == PNG_COLOR_TYPE_RGB ||
        color_type == PNG_COLOR_TYPE_GRAY ||
        color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if(color_type == PNG_COLOR_TYPE_GRAY ||
        color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
    for(int y = 0; y < height; y++)
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));

    png_read_image(png, row_pointers);

    fclose(fp);
    return EXIT_SUCCESS;
}


void processPngFile(void)
{
    for(int y = 0; y < height; y++)
    {
        png_bytep row = row_pointers[y];
        for(int x = 0; x < width; x++)
        {
            png_bytep px = &(row[x * 4]);
            // Do something awesome for each pixel here...
            int result = (((px[0]<<8)|px[1])<<8)|px[2];
            printf("The HEX code of the pixel is: %x\n",result);
        }
    }
}

int main(void)
{
    char fileName[]="didactrgb.png"; //path to the PNG file

    if (checkIfPng(fileName)==EXIT_SUCCESS) //If the file is a PNG file then
    {
        if(readPngFile(fileName)==EXIT_SUCCESS)  //Read the information from that file
        {
            processPngFile();
        }
        else
        {
            perror("ERROR");
        }
    }
    else                                    //Else
        printf("ERROR: The file %s is not a PNG file type.\n",fileName); //Print error message

    return EXIT_SUCCESS;
}
