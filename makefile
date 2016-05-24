all:
	g++ -ggdb -c -O3 -Wall -Wextra  -Wpedantic -pedantic-errors -Wuseless-cast -std=c++11 -I ./glm *.cpp ./Moteur_RTS/*.cpp
	g++ *.o -o oeraumit -lGLEW -lGL -lGLU -lglut -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
