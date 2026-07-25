#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin>>s;
    map<char,int> mp;
    int l = s.size();
    for(int i = 0 ; i<l ; i++)
        mp[s[i]]++;
    int cou = 0;
    for(auto i : mp)
    {
        if(i.second % 2 == 1) cou++;
    }
    if(l % 2 == 1 && cou > 1) 
    {
        cout<<-1; return;
    }
    else if(l%2 == 0 && cou > 0)
    {
        cout<<-1; return;
    }
    long long res = 0;
    int left = 0,right = l - 1;
    while(left < right)
    {
        int pos = right;
        if(s[left] == s[pos])
        {
            left++; right--;
            continue;
        }
        while(s[left] != s[pos]) pos--;
        if(left == pos)
        {
            swap(s[left],s[left+1]);
            res++;
            continue;
        }
        for(int i = pos ; i<right ; i++)
        {
            swap(s[i],s[i+1]);
            res++;
        }
        left++; right--;
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {  
        solve(); cout<<endl;
    }
    return 0;
}