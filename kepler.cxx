#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void Hammilton(double* q, double* p, double& H);
void Step(double* q, double* p, double& H, double dt);

int main(){
	int dim = 2;
	double e = 0.6;
	double q[dim];
	double p[dim];
	double t = 0.0;
	
	double H = -1/2;
	double dt = 0.05;
	double tstart = 0.0;
	double tend = 20*M_PI;
	int Steps = tend/dt;
	q[0] = 1-e;
	q[1] = 0;
	p[0] = 0;
	p[1] = sqrt((1+e)/(1-e));
	
	
	ofstream out("Keplerlol05.txt");
	
	for(int i = 0; i<= Steps; i++){
		
	out << t << "\t" << H << "\t" << p[0] << "\t" << p[1] << "\t" << q[0] << "\t" << q[1] << endl;
    
    Step(q,p,H,dt);
    
    t += dt;
    }
	out.close();
	
	return 0;
	
}

void Hammilton(double* q, double* p, double& H){
H = 1.0/2.0*(p[0]*p[0] + p[1] * p[1]) - 1.0/(sqrt(q[0] * q[0] + q[1] * q[1]));
}

void Step(double* q, double* p, double& H, double dt){
p[0] = p[0] - dt * (q[0]/pow(q[0]*q[0] + q[1] * q[1], 3.0/2.0));	
p[1] = p[1] - dt * (q[1]/pow(q[0]*q[0] + q[1] * q[1], 3.0/2.0));	
	
q[0] = q[0] + dt * p[0];	
q[1] = q[1] + dt * p[1];	

Hammilton(q,p,H);
	
}
