BOOST = -lboost_program_options -lboost_filesystem -lboost_system
CPPFLAGS = -std=c++11 -MD -MP -Wall -pedantic -Wextra
SRC = $(wildcard *.cpp)


all: main

main: $(SRC:%.cpp=%.o)
	@g++ -std=c++11 -o $@ $^ $(BOOST)
	@echo building executable \($@\)
	
clean:
	@rm -rf *.o *.d;
	@echo Cleaned.
	
-include $(SRC:%.cpp=%.d)
	
	