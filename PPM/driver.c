/*************************
 * Cole DiGregorio
 * CPSC 2310 <5>
 * cdigreg@clmeson.edu
 *************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ppm.h"
#include "shape.h"

int main() {
    //open the input file
    FILE *inputFile = fopen("input.txt", "r"); 
    //open output file
    FILE *outputFile = fopen("output.ppm", "wb"); 
    //check if input is open
    assert(inputFile != NULL && "Error: Failed to open input file"); 
    //check is output is open
    assert(outputFile != NULL && "Error: Failed to open output file"); 
    //create a header
    Header header; 
    //create a cricle
    Circle circle; 
    //read input file
    readInput(inputFile, &header, &circle); 
    //write output file
    writeHeader(outputFile, &header); 
    //create the circle in the output file
    createShape(outputFile, &header, &circle); 
    //close
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
