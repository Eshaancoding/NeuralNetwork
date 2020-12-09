#include <iostream>
#include <string>
#include "../NeuralNetwork.hpp"
using namespace std;

void print_array(vector<double> array) {
	for (auto i : array) {
		cout<<i<<" ";
	}
	cout<<endl;
}

vector<double> calc_MSE_dir (vector<double> predicted, vector<double> target) {
	vector<double> output; 
	if (predicted.size() != target.size()) throw invalid_argument("error calc MSE failed");
	for (int i = 0; i < predicted.size(); i++) {
		output.push_back(2*(predicted[i] - target[i]));
	}
	return output;
}

int main () {
	// Neural net
	NeuralNet net ({2,4,2}, 0.01);

	// dataset
	double dataset[8][4] = {
		{3, 1.5, 1, 0}, 
		{2, 1, 0, 1}, 
		{4, 1.5, 1, 0}, 
		{3, 1, 0, 1}, 
		{3.5, 0.5, 1, 0},
		{2, 0.5, 0, 1},
		{5.5, 1, 1, 0}, 
		{1,1,0,1}
	}; 

	// train
	for (int i = 0; i < 100000; i++) {
		int rand_int = rand() % 8;
		vector<double> x_train ( {dataset[rand_int][0], dataset[rand_int][1]} );
		vector<double> y_train( {dataset[rand_int][2], dataset[rand_int][3]} );
		// get error (MSE for this case)
		vector<double> error = calc_MSE_dir(net.predict(x_train),y_train);
		net.apply_grad(x_train, error);  
	}

	// test
	vector<double> output = net.predict({{4.5, 1}});
	if (output[0] > output[1]) {
		string green = "\033[1;32m"; 
		string normal = "\033[0;m";
		cout<<green<<"apply_grad test success! "<<normal<<"Confidence: "<<output[0] - output[1]<<endl;
	} else {
		string red = "\033[1;31m";
		string normal = "\033[0;m";
		cout<<red<<"apply_grad test Failed!"<<normal<<endl; 
	}
}
