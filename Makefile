

main: node.h scene.h main.cpp 
	g++ -g -Wall main.cpp node.h scene.h -o main

clean:
	rm main 
