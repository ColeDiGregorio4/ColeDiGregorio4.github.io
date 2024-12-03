/*************************
 * Cole DiGregorio
 * CPSC 2310 <5>
 * cdigreg@clmeson.edu
 *************************/

#include <stdio.h>
#include <math.h>
#include "shape.h"

//read the input file
void readInput(FILE *inputFile, Header *header, Circle *circle) {
    //get the header width height and max color value
    fscanf(inputFile, "%s %d %d %d", header->format, &header->width, &header->height, &header->maxColorValue);
    //get the center of the circle being created and the radius 
    fscanf(inputFile, "%d %d %d", &circle->center.x, &circle->center.y, &circle->radius);
    //get the color of the circle using RGB format (0,255)
    fscanf(inputFile, "%hhu %hhu %hhu", &circle->color.red, &circle->color.green, &circle->color.blue);
}

//checks if the point given is in the circle
int isInCircle(int x, int y, const Circle *circle) {
    int dx = x - circle->center.x;
    int dy = y - circle->center.y;
    return (sqrt(dx * dx + dy * dy) < circle->radius);
}

//creates the circle
void createShape(FILE *outputFile, const Header *header, const Circle *circle) {
     //sets the background color (this orange is clemson orange)
    Pixel background = {245, 102, 0};
    //for loops to go through each pixel on the output file vertical
    for (int y = 0; y < header->height; y++) { 
        for (int x = 0; x < header->width; x++) {
             //checks if its in the circle
            if (isInCircle(x, y, circle)) {
                 //write the pixel with this color (in circle)
                writePixel(outputFile, &circle->color);
            } else {
                //write the pixel with this color (background)
                writePixel(outputFile, &background); 
            }
        }
    }
}

