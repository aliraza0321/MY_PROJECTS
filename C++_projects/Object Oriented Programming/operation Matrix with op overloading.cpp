#include<iostream>
using namespace std;
class Matrix
{
	int mat[2][2];
public:
	Matrix()
	{
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	Matrix(int m[][2])
	{
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				mat[i][j] =m[i][j];
			}
		}
	}
	Matrix(const Matrix&obj)
	{
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				mat[i][j] =obj.mat[i][j];
			}
		}
	}
	Matrix operator+(Matrix& obj)
	{
		Matrix res;
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				res.mat[i][j] = this->mat[i][j] + obj.mat[i][j];

			}
		}
		return res;
	}
	Matrix operator-(Matrix& obj)
	{
		Matrix res;
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				res.mat[i][j] = this->mat[i][j] - obj.mat[i][j];

			}
		}
		return res;
	}
	Matrix operator-(Matrix& obj)
	{
		Matrix res;
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				res.mat[i][j] = (this->mat[i][0]*obj.mat[0][j])+(this->mat[i][1]*obj.mat[1][j]);
			}
		}
		return res;
	}
	Matrix operator=(const Matrix & obj)
	{
			for (int i = 0;i < 2;i++)
			{
				for (int j = 0;j < 2;j++)
				{
					mat[i][j] = obj.mat[i][j];
				}
			}
			return *this;
    }
	int* operator[](int index)
	{
		return mat[index];
	}
	friend istream& operator>>(istream& input, Matrix& obj);
	friend ostream& operator<<(ostream& print, Matrix& obj);

};
istream& operator>>(istream& input, Matrix& obj)
{
	cout << "Enter values; ";
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			input >> obj.mat[i][j];
		}
	}
	return input;
}
ostream& operator<<(ostream& print, Matrix& obj)
{
	cout << "\nYour Matrix is \n";
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			print<< obj.mat[i][j]<<" ";
		}
		print << endl;
	}
	return print;
}
int main()
{
	Matrix A,B,C;
	cin >> A >> B;
	C = A + B;
	cout<<C;
}
