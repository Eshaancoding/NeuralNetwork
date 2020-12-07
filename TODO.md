## TODO list

- Fix error where backprop for multiple or one dense layers doesn't actually backprop... (refer back to NN notes)
	- The error may be accessing the weights. I will check on that. 
- create new function that doesn't use MSE and use custom functions. (I need to think about this)
- enable batches, then calculate the full MSE for all of those training data in the batches. This enables the training to be much faster. Instead for every training data to have their own weight-update, we could represent a general MSE update for 32 training data.
