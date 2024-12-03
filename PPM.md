# Circle Drawing Program -- PPM
This project involved creating a program that generates a .ppm image containing a single, customizable circle based on input file specifications. The assignment emphasized structured programming, file handling, and the practical application of geometry to computer graphics.
- Parsing Input Files: Reading and interpreting PPM header information, circle parameters (center, radius), and RGB color values from a structured text file.
- Struct Design: Defining and utilizing structs for pixels, points, circles, and headers to maintain organized and reusable code.
- Modular Function Implementation:
- Writing functions to check pixel positions relative to the circle using mathematical principles.
- Creating functions for generating the image by assigning colors to pixels based on their position within or outside the circle.
- Writing the PPM header and pixel data to an output file in the correct format.
- Using Makefiles: Automating the compilation and execution process with a makefile, ensuring efficient testing and debugging.

## Code

<div style="display: flex; gap: 20px; margin-top: 20px;">
    <a href="/PPM/ppm.c" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">ppm.c</a>
    <a href="/PPM/ppm.h" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">ppm.h</a>
    <a href="/PPM/driver.c" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">Driver.cpp</a>
    <a href="/PPM/shape.c" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">shape.c</a>
    <a href="/PPM/shape.h" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">shape.h</a>
    <a href="/PPM/input.txt" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">input.txt</a>
    <a href="/PPM/makefile" style="text-decoration: none; color: white; background-color: #000000; padding: 5px 10px; border-radius: 5px;">makefile</a>
  
</div>
