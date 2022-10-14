#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;
vector<float> nums;

int mult(int x, int y){
    cout << "The product is:" << x*y;
    return x*y;
}

float average(vector<float> nums){
    float sum=0;
    
    for(float ele : nums)
    {
        sum += ele;
    }

    float avg = sum/3;
    return avg;
}

int increment(int value){ return ++value;}

float quadratic(float ind){
    return pow(ind,2) - 1;
}

void bisection(float low, float high, float tol)
    {
        //condition for checking if sign(f(low)) != sign(f(high))
        float mid;
        while (high-low >= tol)
        {
            mid = (high+low) / 2;
            if (quadratic(low)*quadratic(mid) < 0) {high = mid;} //if low and mid have opposite sign
            else{low = mid;}
        }
        mid = (high+low)/2;
        cout << "(x,f(x)) solution is: (" << mid << "," << quadratic(mid) << ")\n";
    }

void bisection2(float low, float high, float tol, int nsteps = 100)
    {
        //condition for checking if sign(f(low)) != sign(f(high))
        if (quadratic(low)*quadratic(high) > 0){
            cout << "Starting points have same sign. Not possible to find root via bisection this way. Please revise.\n";
            return;
        }

        float mid;
        int n=0;
        while (n<nsteps)
        {
            mid = (low+high)/2;
            if ((high-low) <= tol  | abs(quadratic(mid)) < 1e-5) //solution found
            {cout << "(x,f(x)) solution is: (" << mid << "," << quadratic(mid) << ")\n"; return ;}

            else //no solution yet
            {
                if (quadratic(low)*quadratic(mid) < 0) {high = mid;}
                else{low = mid;}
            }
        }
        cout << "solution not found in allotted #/steps. review starting conditions or adjust nsteps.\n";
    }

int main(){
    bisection2(-2.0, 0.6, 0.0001);

    // int x;
    // for(int i=0; i<8; i++)
    // {
    //     x += 5;
    //     cout << "x is: " << x << endl;
    // }

    // vector<float> test = {1.23, 4.56, 8.97};
    // cout << average(test) << endl;
    // cout << test.at(2) << endl;
    
    // int arr[6] = {7,6,3,4,7,8};
    // cout << *arr << endl;

    // int x = 6;
    // x = increment(x);
    // cout << x << endl;
}