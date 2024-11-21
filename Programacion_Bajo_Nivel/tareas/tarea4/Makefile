EXE = main
COMP = g++
FLAGS = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self -fPIC
BLOQUES = criba.o
LIBRERIA = libcriba.so
WRAP = criba_wrap.cxx

all: clean run

$(EXE): main.o
	$(COMP) $(FLAGS) main.o -o $(EXE) -L. -lcriba

%.o: %.cpp %.h
	$(COMP) $(FLAGS) -fPIC -o $@ $< -c

lib: $(BLOQUES)
	$(COMP) -shared $^ -o $(LIBRERIA)

main.o: main.cpp $(BLOQUES)
	$(COMP) $(FLAGS) -o $@ $< -c
	
clean:
	rm -f *.o
	rm -f $(EXE) $(LIBRERIA) _$(PYTHON_BINDING).so
	
run: lib $(EXE)
	./$(EXE)

wrap: criba.i criba.h
	swig -python -c++ criba.i

_libcriba.so: $(WRAP) criba.o
	$(COMP) $(FLAGS) -fPIC -c $(WRAP) -o criba_wrap.o -I/usr/include/python3.x/
	$(COMP) -shared criba_wrap.o $(BLOQUES) -o _$(PYTHON_BINDING).so

python: wrap lib _libcriba.so