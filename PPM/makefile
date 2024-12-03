
 #Cole DiGregorio
 #CPSC 2310 <5>
 #cdigreg@clmeson.edu

CC = gcc
CFLAGS = -Wall

compile: driver.c ppm.c shape.c
	$(CC) $(CFLAGS) -o driver driver.c ppm.c shape.c

run: driver
	./driver

clean:
	rm -f driver
