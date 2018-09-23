#include<math.h>
#include<iostream>

int main()
{
	using namespace std;
	double Init_y[3] = {1,2,3};
    	double Init_x[3][2] = {{0,0},{0,1},{1,0}};
	int Max_step = 10;
	double Init_learn = 0.001;
	double Beta[2] = {0.1,0.1};
	double Gradient[2] = {0,0};
	double sum = 0;
	double sum_beta_x = 0;
	double y_beta_x = 0;
	for(int i=0;i<Max_step;i++)
	{
		for(int j=0;j<sizeof(Init_x)/sizeof(Init_x[0]);j++)
		{
            		sum_beta_x = Beta[0]*Init_x[j][0] + Beta[1]*Init_x[j][1];
			double temp = 2*(Init_y[j]-sum_beta_x);
			Gradient[0] = Gradient[0] + temp*(-Init_x[j][0]);
			Gradient[1] = Gradient[1] + temp*(-Init_x[j][1]);
		} 
		Beta[0]	= Beta[0] - Gradient[0] * Init_learn;
		Beta[1] = Beta[1] - Gradient[1] * Init_learn;
		for(int m=0;m<sizeof(Init_x)/sizeof(Init_x[0]);m++)
		{
			y_beta_x = Init_y[m] - (Beta[0]*Init_x[m][0]+Beta[1]*Init_x[m][1]);
			sum = sum + y_beta_x*y_beta_x;

		}
		cout << "The loss of " << i << " step is " << sum <<";" << endl;
	}
	return 0;

}
