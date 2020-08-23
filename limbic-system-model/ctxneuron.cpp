#include "ctxneuron.h"

float CtxNeuron::doStep(float nonPlasticInput, float serot) {
	output = nonPlasticInput;
	for(int i=0;i<nInputs;i++) {
		output += weights[i] * *(inputs[i]);
	}
	float dOutput = output - output2;
	if (dOutput < 0) dOutput = 0;
	
	for(int i=0;i<nInputs;i++) {
		// weight change: LTP
		weightChange(weights[i], learningRate * serot * *(inputs[i]) * dOutput);
		// weight change: LTD
		weightChange(weights[i], -learningRate * serot * output * 0.01);
	}
	output2 = output;
	return output;
}
