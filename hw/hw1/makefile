# define vars that we will reuse
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# create maze
all: maze

# clean maze
clean:
	rm maze

# compile main.cpp and point.cpp, output it to maze
maze: Player.cpp
	$(CXX) $(CXXFLAGS) main.cpp Player.cpp -o maze
