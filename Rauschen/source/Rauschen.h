#ifndef RAUSCHEN_H
#define RAUSCHEN_H

class Rauschen
{
public:
	Rauschen();
	float generateOutput();
private:
	float arrayA[5];
	float arraySum[5];
	float output;
};

#endif

