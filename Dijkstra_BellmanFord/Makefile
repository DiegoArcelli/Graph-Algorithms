main: main.o Graph.o Node.o Heap.o
	g++ -o main main.o Graph.o Node.o Heap.o

main.o: main.cpp Graph.h
	g++ -c main.cpp

Graph.o: Graph.cpp Graph.h Node.h Heap.h
	g++ -c Graph.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

clean:
	-rm main.o Heap.o Graph.o Node.o main