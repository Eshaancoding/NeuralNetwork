//
//  NeuralNetwork.cpp
//  NeuralNetwork
//
//  Created by Eshaan Arnav on 1/30/20.
//  Copyright © 2020 Eshaan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class NeuralNetwork {
private:
  double e = 2.718281828;
  double learning_rate;
  vector<int> layout;
  vector<vector<vector<double>>> weights;
  vector<vector<double>> bias;
  vector<vector<double>> x;
  double return_random_number () {
    double random_number = double(rand() % 100) / 100;
    return random_number;
  }
  
  // sigmoid for array and single output;
  double sig (double x) {
    return (1 / (1 + pow(e, -x)));
  }

  vector<double> sig (vector<double> x_array) {
    vector<double> sig_array;
    for (int i = 0; i < x_array.size(); i++) {
      double x = x_array[i];
      sig_array.push_back(1 / (1 + pow(e, -x)));
    }
    return sig_array;
  }
  
public:
  
  void print_array (vector<double> array, string array_name) {
    cout<<"-------------"<<array_name<<"----------------"<<endl;
    for (int i = 0; i < array.size(); i++) {
      cout<<array[i]<<", ";
    }
    cout<<endl<<"-----------------END---------------------"<<endl;
  }
  // xcode has a really nice feature where you could look at really long array without creating more code that prints all of it. But in order to look at the array, you must ceate and execute an error.
  void raise_error  () {
    throw invalid_argument("Our own error");
  }
  NeuralNetwork (vector<int> layout, double learning_rate) {
    srand(time(0));
    this->layout = layout;
    this->learning_rate = learning_rate;
    for (int layer = 0; layer < layout.size() - 1; layer++) {
      // build weights
      vector<vector<double>> weights_per_layer;
      for (int c_layer = 0; c_layer < layout[layer]; c_layer++) {
        vector<double> weights_per_c_layer;
        for (int n_layer = 0; n_layer < layout[layer+1]; n_layer++) {
          weights_per_c_layer.push_back(return_random_number());
        }
        weights_per_layer.push_back(weights_per_c_layer);
      }
      weights.push_back(weights_per_layer);
      // build bias
      vector<double> bias_layer;
      for (int n_layer = 0; n_layer < layout[layer+1]; n_layer++) {
        bias_layer.push_back(return_random_number());
      }
      bias.push_back(bias_layer);
    }
  }
  vector<double> predict (vector<double> a) {
    x.clear();
    x.push_back(a);
    for (int layer = 0; layer < weights.size(); layer++) {
      vector<double> layer_predict;
      for (int n_layer = 0; n_layer < layout[layer+1]; n_layer++) {
        double node = 0;
        for (int c_layer = 0; c_layer < layout[layer]; c_layer++) {
          double weight = weights[layer][c_layer][n_layer];
          node += weight * a[c_layer];
        }
        // apply bias
        node += bias[layer][n_layer];
        layer_predict.push_back(node);
      }
      a = sig(layer_predict);
      x.push_back(a);
    }
    return a;
  }
  vector<double> calculate_cost (vector<double> x_train, vector<double> y_train) {
    vector<double> return_array;
    for (int i = 0; i < x_train.size(); i++) {
      return_array.push_back((x_train[i] - y_train[i]) * 2);
    }
    return return_array;
  }

  void train (vector<double> x_train_unpredicted, vector<double> y_train) {
    vector<double> x_train = this->predict(x_train_unpredicted);
    vector<vector<double>> loss_array;
    vector<double> loss = this->calculate_cost(x_train, y_train);
    loss_array.push_back(loss);
    vector<double> previous_loss;
    vector<vector<vector<double>>> weights_grad;
    vector<vector<double>> bias_grad;
    // compute for weights grad
    for (int layer = this->weights.size() - 1; layer > -1; layer--) {
      vector<vector<double>> weights_grad_layer;
      for (int c_layer = 0; c_layer < this->layout[layer]; c_layer++) {
        vector<double> weights_c_layer;
        float previous_loss_for_node = 0;
        for (int n_layer = 0; n_layer < this->layout[layer+1]; n_layer++) {
          double previous_activation = this->x[layer][c_layer];
          double current_activation = this->x[layer+1][n_layer];
          double dir_helper = ((1 - current_activation) * current_activation) * loss[n_layer];
          double dir_weight = previous_activation * dir_helper;
          previous_loss_for_node += weights[layer][c_layer][n_layer] * dir_helper;
          // append weights grad
          weights_c_layer.push_back(dir_weight);
        }
        weights_grad_layer.push_back(weights_c_layer);
        previous_loss.push_back(previous_loss_for_node);
      }
      loss = previous_loss;
      loss_array.push_back(loss);
      previous_loss.clear();
      weights_grad.push_back(weights_grad_layer);
    }
    // reverse weights_grad
    reverse(weights_grad.begin(), weights_grad.end());
    // compute for bias grad
    for (int layer = 0; layer < this->weights.size(); layer++) {
      vector<double> bias_grad_layer;
      for (int n_layer = 0; n_layer < layout[layer+1]; n_layer++) {
        double current_activiation = this->x[layer+1][n_layer];
        double dir_bias = ((1 - current_activiation) * current_activiation) * loss_array[layer+1][n_layer];
        bias_grad_layer.push_back(dir_bias);
      }
      bias_grad.push_back(bias_grad_layer);
    }
    
    // apply grad to weights and bias
    for (int i = 0; i < weights_grad.size(); i++) {
      for (int x = 0; x < weights_grad[i].size(); x++) {
        for (int y = 0; y < weights_grad[i][x].size(); y++) {
          this->weights[i][x][y] -= learning_rate * weights_grad[i][x][y];
        }
      }
    }
    for (int i = 0; i < bias_grad.size(); i++) {
      for (int x = 0; x < bias_grad[i].size(); x++) {
        this->bias[i][x] -= learning_rate * bias_grad[i][x];
      }
    }
  }
};
