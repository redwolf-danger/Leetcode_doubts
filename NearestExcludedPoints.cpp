/*
submission by: advaita soni
*/
#include <iomanip>
#include <ios>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
//#define all(x) (x).begin(), (x).end()
//#define prDouble(x) cout << fixed << setprecision(10) << x
//#define triplet pair<ll,pair<ll,ll>>
//#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define readstr(x) string x;cin>>x
#define readll(x) long long x; cin>>x 
#define vi(name,n,d) vector<int> name (n,d)
#define vl(name,n,d) vector<long long> name (n,d)
#define nl <<"\n";
#define endl "\n"
#define flush cout.flush();

using namespace std;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

ll _power_(ll num, ll p){
    if(p == 0) return 1;
    ll root = _power_(num,p/2);
    return root*root*(p%2 ? num : 1);
};

ll _modinv_(ll num,ll m = mod){
    return pow(num,m-2);
}


//assuming empty array
void read_vec(vector<ll>& arr){
 for(auto& it: arr){
 cin>>it;
 }
 };

 void print_arr(vector<ll>& arr){
 for(auto it:arr){
    cout<<it<<" ";
 };
 cout<<"\n";
 };

int main() {
   init_code();
   int t = 1;
    // cin >> t;
   while(t--){
        readll(n);
        vector<pair<int,int>> order_pts;
        map<pair<int,int>,bool> pts;
        fr(0,n){
        	read(x);
        	read(y);
        	order_pts.pb({x,y});
        	pts[{x,y}] = true;
        };

        // map<pair<int,int>,bool> visited;
        map<pair<int,int>,pair<int,int> > nearestpoints;
        queue<pair<pair<int,int>,pair<int,int>> > bfs; 

        vector<pair<int,int>> sides = {{-1,0},{1,0},{0,1},{0,-1}};

        //make missing points set and do a multisource bfs from it
        for(auto pt: order_pts){
        	// cout nl;
        	// cout<<"pt is "<<pt.first<<" "<<pt.second nl;
        	for(auto jt: sides){
        		pair<int,int> nbr = {pt.first+jt.first,pt.second+jt.second};
        		// cout<<"nbr is "<<nbr.first<<" "<<nbr.second nl;
        		if(abs(nbr.first)>1000000 && abs(nbr.second)>1000000) continue;
        		if(pts[nbr] == false && nearestpoints.count(nbr) == 0){
        			// visited[nbr] = true;
        			nearestpoints[nbr] = nbr;
        			bfs.push({nbr,nbr});
        		};
        	};
        	//add all the blank pts that are not already added
        };


        while(bfs.size()){
        	pair<int,int> pt = bfs.front().first;
        	pair<int,int> empty_pt = bfs.front().second;
        	bfs.pop();
        	for(auto jt: sides){
        		pair<int,int> nbr = {pt.first+jt.first,pt.second+jt.second};
        		if(nearestpoints.count(nbr) == 0 && pts[nbr]){
        			// visited[nbr] = true;
        			nearestpoints[nbr] = empty_pt;
        			bfs.push({nbr,empty_pt});
        		};
        	};
        };
        for(auto it: order_pts){
        	cout<<nearestpoints[it].first<<" "<<nearestpoints[it].second nl;
        }



        //find a way to find the nearest one in o(1) or o(log n)

        //mechanism to rank the points

        // what we can do is do a multisource bfs

        // cout<<"\n";
   }
   return 0;
}
