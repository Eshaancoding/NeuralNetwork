//
//  ExtractMNIST.cpp
//  MNISTDataset
//
//  Created by Eshaan Arnav on 7/2/20.
//  Copyright © 2020 Eshaan. All rights reserved.


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<string> parse(string str,string delim){
    vector<string> tokens;
    char *str_c = strdup(str.c_str());
    char* token = NULL;

    token = strtok(str_c, delim.c_str());
    while (token != NULL) {
        tokens.push_back(std::string(token));
        token = strtok(NULL, delim.c_str());
    }

    delete[] str_c;

    return tokens;
}

vector<vector<double>> training_labels;
vector<vector<double>> training_features;

void extractMNISTData () {
    ifstream file ("Train.txt");
    cout<<"Extracting Data..."<<endl;
    for (string line; getline(file, line);) {
        vector<string> parsing = parse(line, " ");
        bool label = true;
        vector<double> label_array;
        vector<double> features_array;
        for (int i = 0; i < parsing.size(); i++) {
            string look = parsing[i];
            if (look == "|labels") {
                label = true;
            }
            else if (look == "|features") {
                label = false;
            }
            else if (stod(look) >= 0) {
                if (label) {
                    label_array.push_back(stod(look));
                } else {
                    features_array.push_back(stod(look));
                }
            }
            
        }
        training_labels.push_back(label_array);
        training_features.push_back(features_array);
    }
    system("clear");
    cout<<"MNIST Dataset extracted"<<endl;
    cout<<training_features.size()<<endl;
    cout<<training_labels.size()<<endl;
}
