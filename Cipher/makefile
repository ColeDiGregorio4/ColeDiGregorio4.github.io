compile:
	make project3
project3:
	make queue
	make cipher
	make cipherAdvanced
	g++ Project3.cpp Queue.o Cipher.o -Wall -o project3.out
queue:
	g++ Queue.cpp -c 
cipher: 
	g++ Cipher.cpp -c 
cipherAdvanced:
	g++ CipherAdvanced.cpp -c
run:
	 ./project3.out
clean:
	rm -f *.o project3.out
