#include "Rauschen.h"
#include <ctime>
#include <iostream>
#include <cstdlib>


Rauschen::Rauschen()
:
output(0)
{}


float Rauschen::generateOutput(){
		
		float* arrayA = new float[5];
		arrayA[0] = 3.8024;
		arrayA[1] = 2.9694;
		arrayA[2] = 2.5970;
		arrayA[3] = 3.0870;
		arrayA[4] = 3.4006;

		float* arraySum = new float[5];
		arraySum[0] = 0.00198;
		arraySum[1] = 0.01478;
		arraySum[2] = 0.06378;
		arraySum[3] = 0.23378;
		arraySum[4] = 0.91578;
		
		
		float random = static_cast <float>(rand()) / static_cast <float>(RAND_MAX);
		for(int i = 0; i<5; i++){
			if(random <= arraySum[i]){
				float random3 = static_cast <float>(rand()) / static_cast <float>(RAND_MAX);
				output = output + (2* (random3 - 0.5) * arrayA[i]);
			}
		}

		output *= 0.06;
		
		return output;
}