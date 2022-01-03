#include "../NeuralNetwork.hpp"
#include "../utils.cpp"
#include <iostream>
using namespace std;

int main () {
	srand(time(NULL));
	// test length 
	int test_len = 20;
	// retrieve data
	extractMNISTData(); 
	// Init NN
	NeuralNet nn ({784, 500, 50, 10}, 0.01);
	cout<<"Training..."<<endl;
	// Train!
	for (int x = 0; x < 5; x++) {
		for (int i = 0; i < 60000 - test_len; i++) {
			// get random dataset
			int random = rand() % (60000 - test_len);
			double MSE = nn.backprop(training_features[random], training_labels[random]);
		} 	
	}
	// Test!
	float correct = 0f; 
	for (int iteration = 60000 - test_len; iteration < 60000; iteration++) {
		vector<double> prediction = nn.predict(training_features[iteration]); 
		vector<double> target = training_labels[iteration];
		if (argmax(target) == argmax(prediction)) {	
			correct += 1f;
		} else {
			string red = "\033[1;31m";
			string normal = "\033[0;m";	
			cout << red << " Training Failed at iteration " << iteration << normal << endl;
			print_array(prediction);
			print_array(target);
		}
	}
	cout << "Test Success Rate: " << correct / test_len << endl; 
}
