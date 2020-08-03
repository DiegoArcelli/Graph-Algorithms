main: main.o Graph.o Node.o Edge.o
	g++ -o main main.o Graph.o Node.o Edge.o

main.o: main.cpp Graph.h
	g++ -c main.cpp

Graph.o: Graph.cpp Graph.h Node.h Edge.h
	g++ -c Graph.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Edge.o: Edge.cpp Edge.h
	g++ -c Edge.cpp

clean:
	-rm main.o Edge.o Graph.o Node.o main