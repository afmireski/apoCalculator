calculator:
	g++ -c ./src/calculator.cpp -o ./src/calculator.o

	g++ ./src/main.cpp ./src/calculator.o -o ./bin/main

	./bin/main

clean:
	rm ./src/*.o
	rm ./bin/main