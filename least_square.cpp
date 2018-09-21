#include<math.h>

using namespace std;

void main()
{
	double* Init_y = {1,2,3};
    double* Init_x = {0,0;0,1;1,0};
	int Max_step = 100;
	double Init_learn = 0.001;
	double* Beta = {0.1,0.1};
	double* Gradient = {0,0};

	for(int i=0;i<Max_step;i++)
	{
		for(int j=0;j<len(Init_x);j++)
		{
            sum_beta_x = Beta*(Init_x+j).0 + (Beta+1)*(Init_x+j).1;
			temp = 2*((Init_y+j)-sum_beta_x);
			Gradient = Gradient + temp*(Init_x+j).0;
			Gradient+1 = (Gradient+1) + temp*(Init_x+j).1;
		} 
		Beta = Beta - Gradient * Init_learn;
		Beta+1 = (Beta+1) - (Gradient+1) * Init_learn;
	}

}
