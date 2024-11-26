CXX = g++
CXXFLAGS = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self -std=c++11

MAIN = main.cpp
PERSONAJE = Personaje.cpp
PERSONAJE_HEADERS = Personaje.h

PERSONAJES_DIR = personajes
PERSONAJES = $(wildcard $(PERSONAJES_DIR)/*.h)

OBJS = main.o Personaje.o

TARGET = RPG

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: $(MAIN) $(PERSONAJE_HEADERS) $(PERSONAJES)
	$(CXX) $(CXXFLAGS) -c $(MAIN)

Personaje.o: $(PERSONAJE) $(PERSONAJE_HEADERS) $(PERSONAJES)
	$(CXX) $(CXXFLAGS) -c $(PERSONAJE)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)