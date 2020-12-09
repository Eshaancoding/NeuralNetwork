#include "../NeuralNetwork.hpp"
#include "../utils.cpp"
#include <iostream>
using namespace std;

int main () {
	srand(time(NULL));
	// retrieve data
	extractMNISTData(); 
	// Init NN
	NeuralNet nn ({784, 500, 50, 10}, 0.01);
	cout<<"Training..."<<endl;
	// Train!
	for (int x = 0; x < 5; x++) {
		for (int i = 0; i < 59999; i++) {
			// get random dataset
			int random = rand() % 59999;
			double MSE = nn.backprop(training_features[random], training_labels[random]);
		} 	
	}
	// Test!
	vector<double> prediction = nn.predict(training_features[59999]); 
	vector<double> target = training_labels[59999];
	if (argmax(target) == argmax(prediction)) {
		string green = "\033[1;32m";
		string normal = "\033[0;m";	
		cout<<green<<" Training Success!"<<normal<<"Confidence: "<<max(prediction)<<endl;
	} else {
		string red = "\033[1;31m";
		string normal = "\033[0;m";	
		cout<<red<<" Training Failed!"<<normal<<endl;
		print_array(prediction);
		print_array(target);
	}
}
