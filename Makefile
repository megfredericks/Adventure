CXX	= g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: Main

MAIN_OBJECTS = Main.o Stage.o Player.o Item.o
	
Main: $(MAIN_OBJECTS)
	$(CXX) -o $@ $(MAIN_OBJECTS)

clean:
	$(RM) all *.o *~
