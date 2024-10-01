EXE = full
COMP = gcc
FLAGS = -Wall

full: func.o princ.o
	$(COMP) $(FLAGS) -o $(EXE) func.o princ.o

func.o: func.c func.h	
	$(COMP) $(FLAGS) -c func.c -o func.o
	
princ.o: princ.c
	$(COMP) $(FLAGS) -c princ.c -o princ.o
	
clean:
	rm -f *.o
	rm -f $(EXE)	
	
run: $(EXE)
	./$(EXE)
	
all: clean run