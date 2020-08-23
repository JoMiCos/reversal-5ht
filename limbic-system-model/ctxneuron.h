#ifndef _CTXNEURON
#define _CTXNEURON

class CtxNeuron {

public:
	CtxNeuron(float _learningRate) {
		learningRate = _learningRate;
	}
	
	void addInput(float& anInput, float initWeight = 0) {
		if (nInputs == maxInputs) throw "No more inputs.";
		inputs[nInputs] = &anInput;
		weights[nInputs] = initWeight;
		nInputs++;
	}

	float doStep(float nonPlasticInput, float serot);

private:
	float output;
	float output2;
	static const int maxInputs = 10;
	float* inputs[maxInputs];
	float weights[maxInputs];
	int nInputs = 0;
	float learningRate = 0;
	
	void weightChange(float &w, float delta) {
		w += delta;
		if (w>1) w = 1;
		if (w<0) w = 0;
	}
};

#endif
