

main: node.h scene.h main.cpp 
	g++ -std=c++11 -g -Wall main.cpp node.h scene.h -o main

clean:
	rm main 
