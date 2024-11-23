all: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Kuyruk.o -c ./src/Kuyruk.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/DugumAVL.o -c ./src/DugumAVL.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./lib/Avl.o -c ./src/Avl.cpp
	g++ -I ./include/ -o ./bin/text ./lib/Dugum.o ./lib/Kuyruk.o ./lib/Radix.o ./lib/DugumAVL.o ./lib/Dosya.o ./lib/Avl.o  ./src/text.cpp

calistir:
	./bin/text
	



