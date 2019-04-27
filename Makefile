main.o: main.cpp
	g++ -c $<
choice2.o:choice2.cpp
	g++ -c $<
choice3.o:choice3.cpp
	g++ -c $<
choice9.o:choice9.cpp
	g++ -c $<
choice6.o:choice6.cpp
	g++ -c $<
choice7.o:choice7.cpp
	g++ -c $<
target: choice7.o choice6.o choice9.o choice3.o choice2.o main.o
	g++ $^ -o $@
