#include<bits/stdc++.h>
using namespace std;
bool div_7(string s)
{
    int m = 0;
    for(int i = 0 ; i <s.size() ; i++)
    {
        m = (m * 10 + (s[i]-'0')) % 7;
    }
    if(m == 0) return 1;
    return 0;
}
bool div_13(string s)
{
    int m = 0;
    for(int i = 0 ; i <s.size() ; i++)
    {
        m = (m * 10 + (s[i]-'0')) % 13;
    }
    if(m == 0) return 1;
    return 0;
}
void solve()
{
    string s; cin>>s;
    if(div_7(s) && div_13(s)) cout<<"Both";
    else if(div_7(s) && !div_13(s)) cout<<"Div 7";
    else if(!div_7(s) && div_13(s)) cout<<"Div 13";
    else cout<<"None";
    cout<<"\n";
}
int main()
{
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}