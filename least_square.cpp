#include<math.h>
#include<iostream>

class LAYER{
	public:
		LAYER()
		{
			this->row = 3;
			this->col = 2;
			this->Max_step = 1000;
			this->Init_learn = 0.01;		
		}
		LAYER(int row_new, int col_new)
		{
			this->row = row_new;
			this->col = col_new;
		}
		void Gradient_layer(double (*Init_x)[2], double Init_y[], double Beta[])
		{
			for(int i=0;i<Max_step;i++)
			{
				double sum = 0;
				double y_beta_x = 0;
				double Gradient[2] = {0,0};
				for(int j=0;j<row;j++)
				{
					double sum_beta_x = 0;
					
					for(int s=0; s<col; s++)
					{
						sum_beta_x = sum_beta_x + Beta[s]*Init_x[j][s];
					}
				    		
					double temp = 2*(Init_y[j]-sum_beta_x);
					for(int s=0; s<col; s++)
					{
						Gradient[s] = Gradient[s] + temp*(-Init_x[j][s]);
					}
					
				}
				for(int s=0; s<col; s++)
				{
					Beta[s]	= Beta[s] - Gradient[s] * Init_learn;
				} 
				
				for(int m=0;m<row;m++)
				{
					double temp = 0;
					for(int s=0; s<col; s++)
					{
						temp = temp + Beta[s]*Init_x[m][s]; 
					}
					y_beta_x = Init_y[m] - temp;
					sum = sum + y_beta_x*y_beta_x;

				}
				std::cout << "The loss of " << i << " step is " << sum <<";" << std::endl;
			}
			std::cout << "The Beta is " << Beta[0] << " , " << Beta[1] << "." << std::endl;
		}
	private:
		int row;
		int col;
		int Max_step;
		double Init_learn;
};

int main()
{
	LAYER layer;
		
	double Init_y[3] = {1,2,3};
	double Init_x[][2] = {0,0,0,1,1,0};
	double Beta[2] = {0.1,0.1};
	layer.Gradient_layer(Init_x, Init_y, Beta);
	return 0;

}
