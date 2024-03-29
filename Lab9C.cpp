/* Author: Paula Agyeman
Date: 4/20/23
Instructor: Dr.Shresthra
Description: Dynamic Array 
*/

#include <iostream>
using namespace std;

int main()
{
int n,i,minnum;
cout<<"Enter size of the array."<< endl;
cin>>n;
int * numlist = new int[n];
cout<<"Enter array elements." << endl;

for(i=0;i<n;i++)
cin>>*(numlist+i);
minnum=*numlist;

for(i=1;i<n;i++){
	if(*(numlist+i)<minnum)
	minnum=*(numlist+i);
}
cout<<"Min number is "<<minnum;
	delete [] numlist;
}