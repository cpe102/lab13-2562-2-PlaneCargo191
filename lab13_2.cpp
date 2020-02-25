#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double a[][N])
{
	for(int i=0; i<N; i++)
	{
		int j=0;
		cout << "Row " << i+1 <<": ";
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}
}

void findLocalMax(const double b[N][N], bool c[N][N])
{
	for(int j=0; j<N; j++)
	{
		for(int k=0; k<N; k++)
		{
			if(b[j][k] >= b[j-1][k] && b[j][k] >= b[j+1][k] && b[j][k] >= b[j][k-1] && b[j][k] >= b[j][k+1])
			{
				c[j][k]=1;
			}
			else
			{
				c[j][k]=0;
			}
		}
	}
}

void showMatrix(const bool d[N][N])
{
	for(int j=0; j<N; j++)
	{
		for(int k=0; k<N; k++)
		{
			if(j==0 || j==4 || k==0 || k==4)
			{
				cout << "0" << " ";
			}
			else
			{
				if(d[j][k]==1) cout << "1" << " ";
				else cout << "0" << " ";
			}
		}
		cout << endl;
	}
}