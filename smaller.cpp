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
   int t = 1; cin >> t;
   while(t--){
        string s = "a";
        string t = "a";
        read(queries);
        map<char,ll> freq_s;
        map<char,ll> freq_t;
        ll len_s = 1;
        ll len_t = 1;
        freq_s['a']++;
        freq_t['a']++;
        while(queries--){
        	read(d);
        	read(k);
        	readstr(x);
        	if(d == 1){
        		for(auto it: x){
        			freq_s[it] += k;
        			len_s += k;
        		};
        	}
        	else{
        		for(auto it: x){
        			freq_t[it] += k;
        			len_t += k;
        		};
        	};
        	auto s_it = freq_s.begin();
        	auto t_it = freq_t.rbegin();
        	bool possible = false;
        	// bool equal = false;
        	while(s_it != freq_s.end() && t_it != freq_t.rend()){
        		if(s_it->first < t_it->first){
        			possible = true;
        			break;
        		}
        		else if(s_it->first == t_it->first){
        			char comp = s_it->first;
        			int penalty = min(s_it->second,t_it->second);
        			if(s_it->second == penalty){
        				s_it++;
        			};
        			if(t_it->second == penalty){
        				t_it++;
        			};

        			if(s_it == freq_s.end() && t_it!=freq_t.rend()){
        				possible = true;
        				break;
        			}
        			else {
        				break;
        			};
        		}
        		else{
        			break;
        		}
        	} 
        	if(possible){
        		cout<<"YES";
        	}
        	else{
        		cout<<"NO";
        	};
        	cout<<endl;
        };
        // cout<<"\n";
   }
   return 0;
}
