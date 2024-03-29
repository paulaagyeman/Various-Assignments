/* Author: Paula Agyeman
Date: 4/20/23
Instructor: Dr.Shresthra
Description: Array of structures
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct point{
int x, y, z;
double distance;
};

point* readData(ifstream& infile, int size){
point* p = new point[size];
for(int i=0; i<size; i++){
infile >> p[i].x >> p[i].y >> p[i].z;
}
return p;

}


void findMin(point* points, int size, point target, point& min){


min.x = points[0].x;
min.y = points[0].y;
min.z = points[0].z;
min.distance = sqrt(pow(min.x-target.x,2)+pow(min.y-target.y,2)+pow(min.z-target.z,2));
for(int i=0; i<size; i++){
double dist = sqrt(pow(points[i].x-target.x,2)+pow(points[i].y-target.y,2)+pow(points[i].z-target.z,2));
if(dist<min.distance){
min.x = points[i].x;
min.y = points[i].y;
min.z = points[i].z;
min.distance = dist;
}
}


}

int readNumberOfPoints(ifstream& infile){
int size = 0;
int x,y,z;
while(infile>>x>>y>>z){
size++;
}

return size;
}

int main(){

char filename[] = "data.dat";
ifstream infile(filename);
if(!infile){
cout<<"Error: could not find file data.dat";
return 0;
}

int size = readNumberOfPoints(infile);

infile.close();
infile.open(filename);

point* points = readData(infile,size);
point target;
cout<<"Enter a point:\n";
cout<<"x: "; cin >> target.x;
cout<<"y: "; cin >> target.y;
cout<<"z: "; cin >> target.z;

point closest;
findMin(points,size, target, closest);

cout<<"\n\nThe closest point is: \n";
cout<<"x: "<<closest.x<<endl;
cout<<"y: "<<closest.y<<endl;
cout<<"z: "<<closest.z<<endl;
cout<<"distance: " << closest.distance<<endl;

delete[] points;


return 0;
}
