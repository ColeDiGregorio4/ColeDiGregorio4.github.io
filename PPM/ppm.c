/*************************
 * Cole DiGregorio
 * CPSC 2310 <5>
 * cdigreg@clmeson.edu
 *************************/

#include <stdio.h>
#include "ppm.h"

//will write to the header file
void writeHeader(FILE *outputFile, const Header *header) {
    fprintf(outputFile, "%s\n%d %d\n%d\n", header->format, header->width, header->height, header->maxColorValue);
}

//this will write in a pixel to the output file
void writePixel(FILE *outputFile, const Pixel *pixel) {
    fwrite(pixel, sizeof(Pixel), 1, outputFile);
}
