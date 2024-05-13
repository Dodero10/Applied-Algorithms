// P[low, high] --> {True, Flase}, P(i) = True  --> P(j) = True for all j >= i. Find min j

#include<bits/stdc++.h>
using namespace std;

double EPS = 1e-10, low = -1000.0, high = 1000.0;
double x;

bool P(double j){
    return j*j>=x;
}

int main(){

    while(high - low > EPS){
        double mid = (low + high)/2.0;
        if(P(mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    cout << low << endl;

    return 0;
}