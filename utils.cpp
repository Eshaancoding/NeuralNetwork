#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> split(string s) {
    string buf;               
    stringstream ss = stringstream(s);    

    vector<string> tokens; 

    while (ss >> buf)
        tokens.push_back(buf);

    return tokens;
}

vector<vector<double>> training_labels;
vector<vector<double>> training_features;

void extractMNISTData () {
    ifstream file ("../Train.txt");
    if (!file.good()) {	
		string red = "\033[1;31m";
		string normal = "\033[0;m"; 
		cout<<red<<"MNIST Training data not found, exiting test..."<<normal<<endl;
		exit(0); 
	}
	cout<<"Extracting Data..."<<endl;
    for (string line; getline(file, line);) {
        vector<string> parsing = split(line);
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
	// check for the size
    if (training_labels.size() == 60000 && training_features.size() == 60000) {
		string green = "\033[1;32m";	
		string normal = "\033[0;m"; 
		cout<<green<<"Success!"<<normal<<" MNIST Dataset extracted"<<endl; 
	} else {
		string normal = "\033[0;m";
		string red = "\033[1;31m";
		throw invalid_argument(red + "Failed!" + normal + " MNIST Dataset training data has size: " + to_string(training_labels.size())); 
	}
}

double max (vector<double> array) {
    double m;
    for (auto i : array) {
        if (i > m) {
            m = i;
        }
    }
    return m;
}

int argmax (vector<double> array) {
    int index;
    double m;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > m) {
            m = array[i];
            index = i;
        }
    }
    return index;
}

void print_array (vector<double> array) {
	for (auto i : array) {
		cout<<i<<" ";
	}
	cout<<endl; 
}
