CXX = g++
CXXFLAGS = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
TARGET = RPG

all: $(TARGET)

$(TARGET): main.o Personaje.o Medico.o Ingeniero.o
    $(CXX) $(CXXFLAGS) -o $(TARGET) main.o Personaje.o Medico.o Ingeniero.o

main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

Personaje.o: Personaje.cpp Personaje.h
    $(CXX) $(CXXFLAGS) -c Personaje.cpp

Medico.o: Medico.cpp Medico.h
    $(CXX) $(CXXFLAGS) -c Medico.cpp

Ingeniero.o: Ingeniero.cpp Ingeniero.h
    $(CXX) $(CXXFLAGS) -c Ingeniero.cpp

clean:
    rm -f *.o $(TARGET)