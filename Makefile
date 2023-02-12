grammer:
	g++ --std=c++17 -g grammer.* main.cpp -o test.o 
clean:
	rm test.o
test:
	g++ --std=c++17 -g test.cpp -o out.o

