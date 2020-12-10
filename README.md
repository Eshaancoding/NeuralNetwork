# Neural Network in C++

## Tests
Head over to the `test` folder in order to see some examples. If you want to run the MNIST test, then you should download the MNIST dataset from kaggle:
https://www.kaggle.com/darkgeekms/text-file-for-mnist-dataset/data
and then put the file `Train.txt` into the main directory: `NeuralNetwork/`
 
- To run all of these tests, `cd` into the `test` directory and simply type `make` in terminal.
- To run only the MNIST test, simply type: `make MNIST`
- To run only the apply_grad test, simply type: `make Grad`
- To run only the Simple test, simply type: `make Simple`
- To run only the AutoEncoder test, simply type: `make AutoEncoder`

## Resources 

The 3blue1brown neural network youtube series really helped me here: https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi

## The future of this project
This version only runs on the CPU (single-thread), however running a neural network on a GPU is faster and popular among the AI community, and I plan on doing implementing that. However, I am working with a Mac, therefore I can't program the GPU (I could do this on the programming language `swift`,  but I don't like this programming language and I would love to make this project 100% C++ / CUDA). I will have to wait to get a Windows computer with a CUDA-enabled GPU to implement this.

## Email
Any questions contact me: eshaanbarkataki@gmail.com
Made by Eshaan Barkataki
