calculator:
	# g++ -c src/interfaces.hpp -o interfaces.o -g
	g++ -c src/key.cpp -o key.o -g
	g++ -c src/keyboard.cpp -o keyboard.o -g
	g++ -c src/cpu.cpp -o cpu.o -g
	g++ -c src/display.cpp -o display.o -g
	g++ -c src/calculator.cpp -o calculator.o -g
	g++ src/main.cpp *.o -o ./bin/main -g

clean:
	rm *.o
	rm ./bin/main