/*
submission by: advaita soni
*/
#include <iomanip>
#include <ios>
#include<bits/stdc++.h>
#define ll long long
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

ll dp[21][4][2] = {-1};
string number;
ll answer(int digits_undecided,int non_zero_digits,bool bounded){
	if(dp[digits_undecided][non_zero_digits][bounded] != -1) return dp[digits_undecided][non_zero_digits][bounded];
	if(non_zero_digits == 0 || digits_undecided == 0) return 1;
	int upper_bound = 9;
	ll temp = 0;
	if(bounded){
		int lower_bound = number[number.size()-digits_undecided] - '0';
		for(int this_digit = lower_bound;this_digit<=upper_bound;this_digit++){
			if(this_digit == lower_bound && lower_bound == 0){
				temp += answer(digits_undecided-1,non_zero_digits,true);
			}
			else if(this_digit == lower_bound && lower_bound != 0){
				temp+= answer(digits_undecided-1,non_zero_digits-1,true);
			}
			else{
				temp += answer(digits_undecided-1,non_zero_digits-1,false);
			};
		}
	}
	else{
		int lower_bound = 0;
		for(int this_digit = lower_bound;this_digit<=upper_bound;this_digit++){
			if(this_digit == 0) temp += answer(digits_undecided-1,non_zero_digits,false);
			else temp += answer(digits_undecided-1,non_zero_digits-1,false);
		};
	};
	return dp[digits_undecided][non_zero_digits][bounded] = temp;
}

void clear(){
	for(int i = 0;i<=20;i++){
   		for(int j = 0;j<=3;j++){
   			dp[i][j][0] = -1;
   		}
   };
   for(int i = 0;i<=20;i++){
   		for(int j = 0;j<=3;j++){
   			dp[i][j][1] = -1;
   		}
   };
};



int main() {
   init_code();
   clear();
   int t = 1; cin >> t;
   while(t--){
   	readll(a);
   	readll(b);

   	string astr = to_string(a-1);
   	string bstr = to_string(b);

   	string m_a;
   	if(astr.size() != 20){
   		int diff = 20 - astr.size();
   		string temp(diff,'0');
   		m_a = temp + astr;
   	};
   	string m_b; 
   	if(bstr.size() != 20){
   		int diff = 20 - bstr.size();
   		string temp(diff,'0');
   		m_b = temp + bstr;
   	};

   	number = m_a;
   	ll t1 = answer(20,3,true);
   	clear();
   	// cout<<t1 nl;
   	number = m_b;
   	ll t2 = answer(20,3,true);
   	// cout<<t2 nl;
   	clear();
   	cout<<(t1-t2) nl;
   }
   return 0;
}
