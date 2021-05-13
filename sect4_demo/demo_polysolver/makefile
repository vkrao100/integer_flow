CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -O3 -DNDEBUG -DHAVEGETRUSAGE -DHAVEUNLOCKEDIO
DEP=@DEP@

BUILD_PATH=build/
SRC_PATH=includes/
SRC      :=  $(wildcard includes/*.cpp) \

AIGLIB=includes/includes/aiger

OBJECTS := $(SRC:$(SRC_PATH)%.cpp=$(BUILD_PATH)%.o)

all: aiger demo

aiger:
	gcc -O3 -DNDEBUG -c $(AIGLIB).c -o $(AIGLIB).o

$(BUILD_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

demo: $(OBJECTS) 
	$(CC) $(CFLAGS)  -o  $@ demo_polysolver.cpp $(OBJECTS) $(AIGLIB).o -lgmp

clean:
	rm -f demo makefile $(AIGLIB).o \
	rm -rf build/
