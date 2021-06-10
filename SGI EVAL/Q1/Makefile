CXX =g++
RM =rm -f

CXXFLAGS = -Wall -Wextra -pedantic
TARGET = Rectangle

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


cleanWin:
	del -f *.o
	del -f $(TARGET).exe

clean:
	rm -f *.o
	rm -f $(TARGET).exe