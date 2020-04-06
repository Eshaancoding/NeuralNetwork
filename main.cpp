#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "neuralNet.cpp"
using namespace std; 
vector<vector<double>> input;
vector<vector<double>> output;
class trainingData {
public:
    trainingData(string filename) {
        ifstream file;
        file.open(filename);
        string string_int;
        vector<double> x_train_append;
        while (!file.eof()) {
            getline(file, string_int);
            if (string_int.length() == 1) {
                input.push_back(x_train_append);
                x_train_append.clear(); 
                // y_train
                vector<double> y_train_append = zeros(10);
                y_train_append[stoi(string_int)] = 1;
                output.push_back(y_train_append);
            }
            else {
                // x_train
                char char_array[33];
                strcpy(char_array, string_int.c_str());
                for (int i = 0; i < 32; i++) {
                    string append_string (1,char_array[i]);
                    x_train_append.push_back(stoi(append_string));
                }
            }
        }
        file.close();
    }
    
};

int argmax (vector<double> array) {
    int argmax_array = 0;
    for (int i = 0; i  < array.size(); i++) {
        if (array[i] > array[argmax_array]) {
            argmax_array = i;
        }
    }
    return argmax_array;
}

int main () {
    trainingData data ("training"); 
    cout<<"training..."<<endl;
    NeuralNetwork net ({1024,15,10}, 0.7);
    for (int epochs = 0; epochs < 30; epochs++) {
        for (int i = 50; i < input.size(); i++) {
            net.backprop(input[i], output[i]);
        }
        cout<<epochs<<endl; 
    }
    // if you get in the 30's. that's okay! Remember that the training data is only 1,000 images. The real dataset is 60,000 iamges.
    cout<<"testing..."<<endl; 
    int correct = 0;
    for (int i = 0; i < 50; i++) {
        if (argmax(net.predict(input[i])) == argmax(output[i])) {
            correct++; 
        }
    }
    cout<<correct<<endl;
    return 0;
}

