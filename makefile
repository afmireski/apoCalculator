calculator:
	g++ -c src/keyAV.cpp -o keyAV.o -g
	g++ -c src/keyboardAV.cpp -o keyboardAV.o -g
	g++ -c src/cpuAV.cpp -o cpuAV.o -g
	g++ -c src/displayAV.cpp -o display.o -g
	g++ -c src/calculatorAV.cpp -o calculator.o -g
	g++ src/main.cpp *.o -o ./bin/main -g

test:
	g++ -c src/keyAV.cpp -o keyAV.o -g
	g++ -c src/keyboardAV.cpp -o keyboardAV.o -g
	g++ -c src/cpuAV.cpp -o cpuAV.o -g
	g++ -c src/displayAV.cpp -o display.o -g
	g++ -c src/calculatorAV.cpp -o calculator.o -g
	g++ tests/operationTests.cpp *.o -o ./bin/operationTests -g

clean:
	rm *.o
	rm ./bin/*