/*
Daily Coding Problem: Problem #14 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/
#include <bits/stdc++.h>
#define INTERVAL 10000
using namespace std;

int main()
{
    int interval, i;
    double rand_x, rand_y,origin_dist,pi; 
    int circle_point=0, square_point = 0;
    srand(time(NULL));//Initializing rand()
    
    //Total random no. generated = possible x * possible y
    for(i=0;i<(INTERVAL * INTERVAL); i++)
    {
        rand_x = double(rand() % (INTERVAL+1))/INTERVAL;
        rand_y = double(rand() % (INTERVAL+1))/INTERVAL;
        
        //Distance between (x,y) from the origin
        origin_dist = rand_x * rand_x + rand_y *rand_y;
        
        //checking if(x,y) lies inside circle or not with Radius =1 and r**2 = 1
        if(origin_dist <=1 )
            circle_point++;
        //Total no. of point generated
        square_point++;
        
        pi = double(4*circle_point)/square_point;
        //cout<<pi<<endl;//result at every point
    }
    cout<<setprecision(4)<<pi<<endl;
    return 0;
}