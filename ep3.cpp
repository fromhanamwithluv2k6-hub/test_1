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
    int i = 0,j = l-1;
    long long res = 0;
    while(i<j)
    {
        if(s[i] == s[j])
        {
            i++; j--; continue;
        }
        int pos = j;
        while(pos > i && s[pos] != s[i]) pos--;
        if(pos == i)
        {
            swap(s[i],s[i+1]);
            res++;//dua phan tu le ve giua
            continue;
        }
        for(int k = pos ; k<j ; k++)
        {
            swap(s[k],s[k+1]);//dua phan tu gan nhat ben tinh tu ben phai giong voi phan tu ben trai ve vi tri doi xung voi phan tu trai
            res++;
        }
        i++;
        j--;
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