all: main

main: main.o vehiculo.o sedan.o suv.o deportivo.o furgon.o
	g++ -o main main.o vehiculo.o sedan.o suv.o deportivo.o furgon.o

main.o: main.cpp
	g++ -c main.cpp

vehiculo.o: vehiculo.cpp vehiculo.h
	g++ -c vehiculo.cpp

sedan.o: sedan.cpp sedan.h
	g++ -c sedan.cpp

suv.o: suv.cpp suv.h
	g++ -c suv.cpp

deportivo.o: deportivo.cpp deportivo.h
	g++ -c deportivo.cpp

furgon.o: furgon.cpp furgon.h
	g++ -c furgon.cpp

clean:
	rm -f *.o main

run: main
	./main