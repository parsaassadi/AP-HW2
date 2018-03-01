CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = Qmain.o Queue.o
TARGET = Qmain


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
Qmain.o: Qmain.cpp Queue.h
	$(CXX) $(CXXFLAGS) Qmain.cpp
Queue.o: queue.cpp
	$(CXX) $(CXXFLAGS) Queue.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
