#include "../NeuralNetwork.hpp" // file is out of this directory
#include <iostream> 
using namespace std;

void print_array (vector<double> array) {
	for (auto i : array) {
		cout<<i<<", ";
	}
	cout<<endl;
}

double calculate_score (vector<double> one, vector<double> two) {
	double score; 
	if (one.size() != two.size()) {
		throw invalid_argument("Error when calculating score");
	}
	for (int i = 0; i < one.size(); i++) {
		score += abs(one[i] - two[i]); 
	}

	return score / one.size();
}

int main () {
	// variables
	int dataset_len = 50; 
	int iterations = 1000000;	

	// init NN
	NeuralNet net ({100, 50, 20, 20, 50, 100}, 0.01); 
	
	// random 
	srand(time(NULL));	
	
	// get training data:
	vector<vector<double>> train;	
	for (int i = 0; i < dataset_len; i++) {
		// generate train
		vector<double> push;	
		for (int x = 0; x < 100; x++) {
			double random_num = (rand() % 1000) / double(1000);
			push.push_back(random_num);
		}
		train.push_back(push);
	}
	
	// iteration loop!
	for (int i = 0; i < iterations; i++) {
		int random_number = rand() % dataset_len;
		net.backprop_mse(train[random_number], train[random_number]); 
	}

	// test
	int random_number = rand() % dataset_len;
	vector<double> prediction = net.predict(train[random_number]);
	double output = calculate_score(prediction, train[random_number]);
	if (1 - output > 0.95) {
		string green = "\033[1;32m";
		string normal = "\033[0;m";
		cout<<green<<"Success!"<<normal<<" Confidence: "<<1-output<<endl;
	} else {
		string red = "\033[1;31m";
		string normal = "\033[0;m";
		cout<<red<<"Failed!"<<normal<<" Confidence: "<<1-output<<endl;
	}
}
