EXENAME = main
OBJS = main.o TreeNode.o TreeNodeGiven.o
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

TreeNode.o: TreeNode.cpp
	$(CXX) $< $(CXXFLAGS)

TreeNodeGiven.o: TreeNodeGiven.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
