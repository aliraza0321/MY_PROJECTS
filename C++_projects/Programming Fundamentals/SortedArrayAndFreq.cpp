
#include<iostream>
using namespace std;
int main()
{
	int Arr[100];
	int Us[100];
	int Freq[100];
	int Freq2[100];
	int count = 0;
	int frequency = 0;
	cout << "Enter the values of array :\n";
	for (int i = 0; i < 100; i++)
	{
		cin >> Arr[i];
		if (Arr[i] == -99)
			break;
		count++;
	}
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < count; i++)
	{
		frequency = 0;
		count2 = 0;
		for (int j = 0; j < count; j++)
		{
			if (Arr[i] == Us[j] && i != j)
			{
				count2++;
			}
			if (Arr[i] == Arr[j])
			{
				frequency++;
			}
		}
		Freq[count3] = frequency;
		Freq2[i] = frequency;

		if (count2 == 0)
		{
			Us[count3] = Arr[i];
			count3++;
		}
	}
	cout << "Us array is ";
	for (int d = 0; d < count3; d++)
	{
		cout << Us[d] << " ";
	}
	cout << endl;
	cout << "Freq ";
	for (int h = 0; h < count3; h++)
	{
		cout << Freq[h] << " ";
	}
	cout << endl;
	int tempElement = 0, tempFreq = 0;
	for (int l = 0; l < count3 - 1; l++)
	{
		for (int y = 0; y < count3 - 1 - l; y++)
		{
			if (Freq[y] > Freq[y + 1])     //check frequency and swap in order
			{
				tempFreq = Freq[y];
				Freq[y] = Freq[y + 1];
				Freq[y + 1] = tempFreq;

				tempElement = Us[y];
				Us[y] = Us[y + 1];
				Us[y + 1] = tempElement;
			}
		}
	}
	cout << "Sorted Us : ";
	for (int b = (count3 - 1); b >= 0; b--)
	{
		cout << Us[b] << " ";
	}
	cout << "\nNew D-Array : ";
	int tempElement1 = 0, tempFreq1 = 0;
	for (int l = 0; l < count - 1; l++)
	{
		for (int y = 0; y < count - 1 - l; y++)
		{
			if (Freq2[y] > Freq2[y + 1])
			{
				tempFreq1 = Freq2[y];
				Freq2[y] = Freq2[y + 1];
				Freq2[y + 1] = tempFreq1;

				tempElement1 = Arr[y];
				Arr[y] = Arr[y + 1];
				Arr[y + 1] = tempElement1;
			}
		}
	}
	for (int y = count - 1; y >= 0; y--)
	{
		cout << Arr[y] << " ";
	}
}