make: 
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp testOne.cpp -o main 
	@./main
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp test.cpp -o main 
	@./main
	@rm main

debug: 	
	@echo Creating object file...
	@c++ -std=c++11 -g -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp test.cpp -o main
	@echo Object file completed	

clean: 
	@rm main 
	@rm main.dSYM 
