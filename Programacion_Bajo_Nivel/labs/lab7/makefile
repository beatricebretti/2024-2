EXE = app
COMP = g++
FLAGS = -Wall

$(EXE): vehiculo.o app.o
	$(COMP) $(FLAGS) -o $(EXE) vehiculo.o app.o

vehiculo.o: vehiculo.cpp vehiculo.h
	$(COMP) $(FLAGS) -c vehiculo.cpp -o vehiculo.o

app.o: app.cpp vehiculo.h
	$(COMP) $(FLAGS) -c app.cpp -o app.o

clean:
	rm -f *.o
	rm -f $(EXE)

run: $(EXE)
	./$(EXE)

all: clean run

