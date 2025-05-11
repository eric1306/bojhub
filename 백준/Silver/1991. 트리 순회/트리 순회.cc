//Authored by: prid1306
#include <bits/stdc++.h>
using namespace std;
int n;
int lc[27];
int rc[27];
void preorder(int cur)
{
    cout<<(char)(cur + 'A');
    if(lc[cur]) preorder(lc[cur]);
    if(rc[cur]) preorder(rc[cur]);
}
void inorder(int cur)
{
    if(lc[cur]) inorder(lc[cur]);
    cout<<(char)(cur + 'A');
    if(rc[cur]) inorder(rc[cur]);
}
void postorder(int cur)
{
    if(lc[cur]) postorder(lc[cur]);
    if(rc[cur]) postorder(rc[cur]);
    cout<<(char)(cur + 'A');
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    char node, left, right;
    for(int i=0;i<n;i++)
    {
        cin>>node>>left>>right;
        if(left!='.') lc[node - 'A'] = left - 'A';
        if(right!='.') rc[node - 'A'] = right - 'A';
    }
    preorder(0);
    cout<<'\n';
    inorder(0);
    cout<<'\n';
    postorder(0);
} 