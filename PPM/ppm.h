/*************************
 * Cole DiGregorio
 * CPSC 2310 <5>
 * cdigreg@clmeson.edu
 *************************/

#ifndef PPM_H
#define PPM_H

#include <stdio.h>

//struct for the header 
typedef struct {
    char format[1];
    int width; 
    int height;
    int maxColorValue;
} Header;

//struct for pixel color
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

/*
 * Parameters:
 *      outputFile: Pointer to the output file where the header will be written
 *      header: A pointer to a Header struct containing the image metadata
 * 
 * Return:
 *      This function generates the header section for the ppm file based on the 
 *      information in the Header struct and writes it to the output file
 */

void writeHeader(FILE *outputFile, const Header *header);

/*
 * Parameters:
 *      outputFile: pointer to the output file where the pixel data will be written
 *      pixel: a pixel struct containing the RGB values to be written
 *
 * Return:
 *      This function writes the RGB values of a single pixel to the ppm file
 */

void writePixel(FILE *outputFile, const Pixel *pixel);

#endif

