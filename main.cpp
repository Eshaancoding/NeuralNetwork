//
//  main.cpp
//  MNISTDataset
//
//  Created by Eshaan Arnav on 7/2/20.
//  Copyright © 2020 Eshaan. All rights reserved.
//
#include "NeuralNetwork.cpp"
#include "ExtractMNIST.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;
int main () {
    extractMNISTData();
    NeuralNetwork net ({784, 128, 10}, 0.001);
    for (int x = 0; x < 5; x++) {
        cout<<"EPOCH: "<<x<<endl;
        for (int i = 0; i < 59999; i++) {
            net.backprop(training_features[i], training_labels[i]);
        }
    }
    print_array(net.predict(training_features[59999]));
    print_array(training_labels[59999]);
}

