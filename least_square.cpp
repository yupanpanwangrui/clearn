#include<math.h>
#include<iostream>

int main()
{
	using namespace std;
	double Init_y[4] = {1,2,3,4};
    double Init_x[4][3] = {{0,0,0},{0,1,0},{1,0,0},{0,0,0}};
	int Max_step = 1000;
	double Init_learn = 0.01;
	double Beta[3] = {0.1,0.1,0.1};	
	for(int i=0;i<Max_step;i++)
	{
		double sum = 0;
		double y_beta_x = 0;
		double Gradient[3] = {0,0,0};
		for(int j=0;j<sizeof(Init_x)/sizeof(Init_x[0]);j++)
		{
			double sum_beta_x = 0;
			
			for(int s=0; s<sizeof(Init_x[0])/sizeof(Init_x[0][0]); s++)
			{
				sum_beta_x = sum_beta_x + Beta[s]*Init_x[j][s];
			}
            		
			double temp = 2*(Init_y[j]-sum_beta_x);
			for(int s=0; s<sizeof(Init_x[0])/sizeof(Init_x[0][0]); s++)
			{
				Gradient[s] = Gradient[s] + temp*(-Init_x[j][s]);
			}
			
		}
		for(int s=0; s<sizeof(Init_x[0])/sizeof(Init_x[0][0]); s++)
		{
			Beta[s]	= Beta[s] - Gradient[s] * Init_learn;
		} 
		
		for(int m=0;m<sizeof(Init_x)/sizeof(Init_x[0]);m++)
		{
			double temp = 0;
			for(int s=0; s<sizeof(Init_x[0])/sizeof(Init_x[0][0]); s++)
			{
				temp = temp + Beta[s]*Init_x[m][s]; 
			}
			y_beta_x = Init_y[m] - temp;
			sum = sum + y_beta_x*y_beta_x;

		}
		cout << "The loss of " << i << " step is " << sum <<";" << endl;
	}
	cout << "The final beta is " << Beta[0] << " , " << Beta[1] << ";" << endl;
	return 0;

}
