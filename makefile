all:
	g++ -c -std=c++11 -I ./glm *.cpp
	g++ *.o -o tamer -lGLEW -lGL -lGLU -lglut -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
