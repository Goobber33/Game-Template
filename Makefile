CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = MyGame

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f src/*.o $(EXEC)
