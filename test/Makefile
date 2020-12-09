make: 
	@echo Running MNIST test
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp MNISTest.cpp -o main 
	@./main
	
	@echo Running apply_grad test
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp apply_grad.cpp -o main 
	@./main
		
	@echo Running SimpleNN test
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp SimpleNN.cpp -o main 
	@./main
	
	@echo Running AutoEncoder test
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp AutoEncoder.cpp -o main 
	@./main
	@rm main

MNIST: 
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp MNISTest.cpp -o main 
	@./main
	@rm main

Grad:
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp apply_grad.cpp -o main 
	@./main
	@rm main

Simple:
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp SimpleNN.cpp -o main 
	@./main
	@rm main

AutoEncoder:
	@c++ -std=c++11 -I ../NeuralNetwork.hpp ../NeuralNetwork.cpp AutoEncoder.cpp -o main 
	@./main
	@rm main
