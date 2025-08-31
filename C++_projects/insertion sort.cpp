 #include<iostream>
using namespace std;
int main()
{
	int i,j,val;
	int arr[4]={19,12,5,7};
	for(int i=1;i<4;i++)
	{
		val=arr[i];
		j=i-1;
		while(val<arr[j]&&j!=-1)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=val;
	}
	for(int i=0;i<4;i++)
	{
		cout<<arr[i]<<" ";
	}
}