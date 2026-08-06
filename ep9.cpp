#include<bits/stdc++.h>
using namespace std;
int n; long long m;
vector<long long> a;
vector<char> ops;
int ans;
long long cal()
{
    long long res = 0;
    stack<long long> st;
    st.push(a[0] % m);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(ops[i] == '*')
        {
            long long last =st.top(); st.pop();
            st.push(last* a[i+1] % m);
        }
        else if(ops[i] == '+')
            st.push(a[i+1] % m);
        else
            st.push(-a[i+1] % m);
    }
    while(!st.empty())
    {
        res += st.top();
        res %= m;
        st.pop();
    }
    return res;
}
void Try(int pos)
{
    if(pos == n - 1)
    {
        if(cal() % m == 0)
        {   
            ans++;
        }
        return;
    }
    ops[pos] = '+';
    Try(pos+1);
    ops[pos] = '-';
    Try(pos+1);
    ops[pos] = '*';
    Try(pos+1);
}
void solve()
{
    cin>>n>>m;
    ans = 0;
    a.resize(n);
    ops.resize(n-1);
    for(int i = 0 ; i<n  ;i++) cin>>a[i];
    Try(0);
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}