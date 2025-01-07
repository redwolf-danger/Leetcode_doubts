#include <iomanip>
#include <ios>
#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define readll(x) long long x; cin>>x 
#define nl <<"\n";

using namespace std;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

vector<vector<ll>> adj_list;
vector<ll> node_color;
vector<ll> subtree_color;
vector<bool> root;

//color coding
//0 means multi color
// 

void color_subtree(int node,int parent){
	if(adj_list[node].size() == 1 && parent>0){
		subtree_color[node] = node_color[node];
		
		return;
	};

	ll maxi = INT_MIN;
	ll mini = INT_MAX;
	for(auto it: adj_list[node]){
		if(it!= parent){
			color_subtree(it,node);
			maxi = max(maxi,subtree_color[it]);
			mini = min(mini,subtree_color[it]);
		};
	};
	if(maxi == mini && maxi == node_color[node]){
		subtree_color[node]  = node_color[node];
	}
	else{
		subtree_color[node] = 0;
	};
	return;


}
void dfs(int node,int parent,int parent_subtree_color){
	if(parent_subtree_color == 0){
		return;
	};
	bool single_color = true; 
	multiset<int> colors;
	colors.insert(parent_subtree_color);
	colors.insert(node_color[node]);
	for(auto it: adj_list[node]){
		if(it!= parent && subtree_color[it] == 0){
				single_color = false;
		};
		colors.insert(subtree_color[it]);
	};
	if(!single_color){
		for(auto it: adj_list[node]){
		if(it != parent){
			colors.erase(subtree_color[it]);
			int parent_subtree_color = 0;
			if( *(colors.begin()) == *(colors.rbegin())){
				parent_subtree_color = node_color[node];
			};
			dfs(it,node,parent_subtree_color);
			colors.insert(subtree_color[it]);
		};
	};
	}
	else{
		root[node] = true;
		return;
	};
};
int main() {
   init_code();
   int t = 1; 
   while(t--){
   	readll(n);
   	adj_list.resize(n+1);
   	node_color.resize(n+1);
   	subtree_color.resize(n+1);
   	root.resize(n+1,false);
   	fr(0,n-1){
   		readll(u);
   		readll(v);
   		adj_list[u].push_back(v);
   		adj_list[v].push_back(u);
   	};
   	fr(1,n+1){
   		cin>>node_color[i];
   	}; 
   	color_subtree(1,-1);
   	dfs(1,0,node_color[1]); 
   	bool poss = false;
   	int vertex = 0;
   	for(int i =0;i<n+1;i++){
   		if(root[i]){
   			poss = true;
   			vertex = i;
   		};
   	};
   	if(poss){
   		cout<<"YES" nl;
   		cout<<vertex;
   	}
   	else{
   		cout<<"NO";
   	};
    cout<<"\n";
   }
   return 0;
}
