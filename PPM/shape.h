/*************************
 * Cole DiGregorio
 * CPSC 2310 <5>
 * cdigreg@clmeson.edu
 *************************/

#ifndef SHAPE_H
#define SHAPE_H

#include "ppm.h"

//struct for point 
typedef struct {
    int x;
    int y;
} Point;

//struct for circle
typedef struct {
    Point center;
    int radius;
    Pixel color;
} Circle;

int isInCircle(int x, int y, const Circle *circle);
/*
 * Parameters:
 *      inputFile: Pointer to the input file containing shape information
 *      circle: A pointer to a Circle struct that will store the read data
 * Return:
 * This function reads the circles center point radius and color data from the input file
 */
 
void readInput(FILE *inputFile, Header *header, Circle *circle);

/*
 * Parameters:
 *      x: The x-coordinate of the pixel to check
 *      y: The y-coordinate of the pixel to check
 *      circle: A pointer to the Circle struct containing the circle's data
 * Return:
 * This function calculates whether the point (x, y) is within the circle by checking if
 * the distance from the center of the circle is less than or equal to the circles radius
 */

void createShape(FILE *outputFile, const Header *header, const Circle *circle);

#endif
