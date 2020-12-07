//
//  NeuralNet.hpp
//  NeuralNet
//
//  Created by Eshaan Arnav on 9/7/20.
//  Copyright © 2020 Eshaan. All rights reserved.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

#endif /* NeuralNet_hpp */

class Layer {
public:
    double* weights;
    double* bias;
    int starting_node;
    int ending_node;
    double e = 2.7182818;
    double lr;

    Layer (int starting_node, int ending_node, double lr);
    vector<double> predict (vector<double> input);
    vector<double> backprop(vector<double> inputs, vector<double> outputs, vector<double> target); 
    
    void free_vars ();
    double sigmoid (double x);
};

class NeuralNet {
private:
    Layer *layers;
    int layout_size = 0;
    int output_layout;
    double lr;
    double mean (vector<double> array);
    vector<double> subtract (vector<double> arrayOne, vector<double> arrayTwo);
    vector<double> square (vector<double> arrayOne);
	vector<double> multiply (vector<double> arrayOne, double two);
public:
    NeuralNet (vector<int> layout, double lr);
    vector<double> predict (vector<double> input);
    double backprop_mse(vector<double> input, vector<double> expected_output);
};

