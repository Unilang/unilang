CPPFLAGS = -std=c++11 -O3 -MD -MP -Wall -pedantic -Wextra
SRC = $(wildcard *.cpp)


all: main

main: $(SRC:%.cpp=%.o)
	g++ -std=c++11 -o $@ $^
	
clean:
	rm -rf *.o *.d main;
	
-include $(SRC:%.cpp=%.d)
	