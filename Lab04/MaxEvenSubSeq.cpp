#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[1000001];

long long getMaxMid(int low, int mid, int high){
    long long even_max_left = LONG_MIN;
    long long odd_max_left = LONG_MIN;
    long long max_left = 0;
    
    for(int i=mid; i>=low; i--){
        max_left += a[i];
        if(max_left%2==0 && max_left>even_max_left) even_max_left = max_left;
        if(max_left%2==1 && max_left>odd_max_left)  odd_max_left = max_left;
    }
    
    long long even_max_right = LONG_MIN;
    long long odd_max_right = LONG_MIN;
    long long max_right = 0;
    
    for(int i=mid+1; i<=high; i++){
        max_right += a[i];
        if(max_right%2==0 && max_right>even_max_right)  even_max_right = max_right;
        if(max_right%2==1 && max_right>odd_max_right)   odd_max_right = max_right;
    }
    
    if(even_max_left==LONG_MIN)  even_max_left = 0;
    if(odd_max_left==LONG_MIN)   odd_max_left = 0;
    if(even_max_right==LONG_MIN) even_max_right = 0;
    if(odd_max_right==LONG_MIN)  odd_max_right = 0;
    
    long long max1 = even_max_right + even_max_left;
    long long max2 = odd_max_right + odd_max_left;
    
    if(max1==0) max1 = -1;
    if(max2==0) max2 = -1;
    
    if(max1!=-1 && max2!=-1) return max(max1, max2);
    else if(max1!=-1)   return max2;
    else return max1;
}

long long getMax(int low, int high){
    if(low==high) return -1;
    
    long long mid = low - (low-high)/2;
    
    long long maxLeft = getMax(low, mid);
    long long maxRight = getMax(mid+1, high);
    long long maxMid = getMaxMid(low, mid, high);
    
    return max(max(maxLeft, maxRight), maxMid);
}


int main(){
    cin >> n;
    
    for(int i=0; i<n; i++)  cin >> a[i];
    
    cout << getMax(0, n-1);
    
    return 0;
}
