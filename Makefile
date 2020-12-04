make: 
	@clear
	@c++ -std=c++11 -I NeuralNetwork.hpp NeuralNetwork.cpp main.cpp -o main
	@./main
	@rm main
