/* Author: Paula Agyeman
Date: 4/20/23
Instructor: Dr.Shresthra
Description: Dynamic Array
*/

#include<iostream>
using namespace std;

int main(){
	double *array; 
	int size;
	cout<<"Enter the size of an array: ";
	cin>>size;
	array = new double[size]; 

	cout<<"Enter the elements of array: "<<endl;
	for (int i = 0; i < size; i++)
	{
		cin>>*(array + i); 
	}

	//ascending order
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(array + i) > *(array + j))
			{
				double temp;
				temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
			}
		}
	}

	cout<<"The elements of array in ascending order :"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout<<*(array + i)<<"\t"; 
	}
	cout<<endl;	
	delete [] arrray;

	return 0;
}