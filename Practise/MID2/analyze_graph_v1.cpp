// cho một đồ thị vô hướng trên mặt phẳng, mỗi đỉnh (điểm) có một tọa độ. giữa các điểm có các đoạn (cạnh) nối các cặp điểm với nhau. thực hiện một loạt truy vấn thuộc các loại sau:

// ?number_points: trả về số lượng điểm (hoặc đỉnh) của đồ thị

// ?number_segments: trả về số lượng đoạn (hoặc cạnh) của đồ thị

// ?connected_components: trả về số lượng thành phần liên thông của đồ thị

// ?longest_cycle_from <PointID>: trả về số lượng cạnh của chu trình dài nhất (độ dài của chu trình được tính bằng số lượng cạnh của chu trình) bắt đầu từ điểm <PointID> ghé thăm các điểm khác (mỗi điểm được ghé thăm đúng một lần) và kết thúc tại điểm <PointID>

// đầu vào

// khối đầu tiên là một dãy các dòng, mỗi dòng chứa thông tin của một điểm với định dạng sau:

// <PointID> <x_coordinate> <y_coordinate>

// <PointID>: chuỗi có độ dài từ 2 đến 7 đại diện cho mã định danh của điểm

// <x_coordinate>, <y_coordinate>: các số nguyên đại diện cho tọa độ của điểm

// khối đầu tiên kết thúc bằng một dòng chứa ký tự #

// khối thứ hai là một dãy các dòng, mỗi dòng chứa thông tin về một đoạn với định dạng sau:

// <SegmentID> <PointID1> <PointID2>

// <SegmentID>: chuỗi có độ dài từ 2 đến 7 đại diện cho mã định danh của đoạn

// <PointID1>, <PointID2>: chuỗi đại diện cho mã định danh của 2 điểm của đoạn

// khối thứ hai kết thúc bằng một dòng chứa ký tự #

// khối thứ ba là một dãy các dòng, mỗi dòng là một truy vấn thuộc các loại đã mô tả ở trên. khối thứ ba kết thúc bằng một dòng chứa ký tự ###

// đầu ra

// viết mỗi dòng kết quả của truy vấn tương ứng

// ví dụ

// đầu vào:

// p01 0 0

// p02 0 1

// p03 0 2

// p04 1 0

// p05 1 1

// p06 1 2

// p07 2 0

// p08 2 1

// p09 2 2

// s01 p01 p02

// s02 p02 p03

// s03 p04 p05

// s04 p05 p06

// s05 p07 p08

// s06 p08 p09

// s07 p01 p04

// s08 p04 p07

// s09 p02 p05

// s10 p05 p08

// s11 p03 p06

// s12 p06 p09

// ?number_points

// ?number_segments

// ?connected_components

// ?longest_cycle_from p01

// đầu ra

// 9

// 12

// 1

// 8


#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x, y;
};

int n=0;
int e=0;
int k=0;
unordered_map<string, Point> p;
unordered_map<string, int> visited;
unordered_map<string, vector<string>> g;

void dfs(){
    std::stack<string> s ;
    for(auto pair: p){
        if(visited[pair.first]!=1){
            k++;
            s.push(pair.first);
            while(!s.empty()){
                string u=s.top();
                s.pop();
                visited[u]=1;
                for(string v: g[u]){
                    if(visited[v]==0){
                        s.push(v);
                    }
                }
            }
        }
    }
}

int dfs1(string node){
    unordered_map<string, int> visited1;
    int res=1;
    std::stack<pair<string, int>> s ;
    s.push({node,0});
    while(!s.empty()){
        auto u=s.top();
        s.pop();
        visited1[u.first]=1;
        for(string v: g[u.first]){
            if(visited1.find(v)!=visited1.end()){
                s.push({v,u.second+1});
            }
            if(v==node){
                return u.second+1;
            }
        }
    }
    return res;
}

int main(){
    string s;
	while(1){
		cin >>s;
		if(s=="#") break;
		Point u;
		cin >>u.x>>u.y;
		p[s]=u;
		n++;
		g[s]={};
		visited[s]=0;
	}
	
	while(1){
		cin >> s;
		if(s=="#") break;
		string node1, node2;
		cin>>node1>>node2;
		g[node1].push_back(node2);
		g[node2].push_back(node1);
		e++;
	}
	bool check=false;
	while(1){
	    cin>>s;
	    if(s=="###") break;
	    if(s=="?number_points") cout<<n<<endl;
	    if(s=="?number_segments") cout<<e<<endl;
	    if(s=="?connected_components"){
	        if(!check){
	            dfs();
	        }
	        cout<<k<<endl;
	    }
	    if(s=="?longest_cycle_from"){
	        string node;
	        cin>>node;
	        cout<<dfs1(node);
	        
	    }
	 
	}
}