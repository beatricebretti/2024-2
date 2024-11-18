CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = ensamblaje

all: $(TARGET)

$(TARGET): main.o ensamblaje.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o ensamblaje.o

main.o: main.cpp ensamblaje.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Ensamblaje.o: ensamblaje.cpp ensamblaje.h
	$(CXX) $(CXXFLAGS) -c ensamblaje.cpp

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)