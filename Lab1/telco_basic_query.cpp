#include<bits/stdc++.h>
using namespace std;

bool check_phone_number = true;
map<string,int> number_calls_from;
map<string,int> count_time_calls_from;
int total = 0;

int str2int(string a){
    return stoi(a.substr(0, 2)) * 3600 + stoi(a.substr(3, 5)) * 60 + stoi(a.substr(6, 8));
}

bool isPhoneNumber(string s){
    for(auto x : s){
        if(!isdigit(x)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string call = "", from_number, to_number, date, from_time, end_time;
    
    while(true){
        cin >> call;
        if(call == "#") break;
        
        cin >> from_number >> to_number >> date >> from_time >> end_time;
        total += 1;
        number_calls_from[from_number] +=1;
        int duration = str2int(end_time) - str2int(from_time);
        count_time_calls_from[from_number] += duration;
        if(check_phone_number){
            if(!isPhoneNumber(from_number) || !isPhoneNumber(to_number)) check_phone_number=false;
        }
    }
    
    while(true){
        cin >> call;
        if(call == "#") break;
        if(call == "?check_phone_number"){
            if(check_phone_number)  cout << 1 << endl;
            else    cout << 0 << endl;
        }
        else if(call == "?number_calls_from"){
            cin >> from_number;
            cout << number_calls_from[from_number] << endl;
        }
        else if(call == "?number_total_calls")   cout << total << endl;
        else{
            cin >> from_number;
            cout << count_time_calls_from[from_number]<< endl;
        }
    }
    
    return 0;
}