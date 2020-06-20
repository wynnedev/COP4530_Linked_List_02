list : mydriver.o 
	-g++ -o list mydriver.o 

mydriver.o : mydriver.cpp List.h
	-g++ -c -std=c++14 mydriver.cpp

clean : 
	rm list *.o