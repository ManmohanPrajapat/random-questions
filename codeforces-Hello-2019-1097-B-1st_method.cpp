#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define int long long int
#define float long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX_SIZE = 1000001; 
// ll fastexpo(ll x,ll n,ll M)
// {
//     if(n==0)
//         return 1;
//     else if(n%2 == 0)        //n is even
//         return fastexpo(((x%M)*(x%M))%M,n/2,M);
//     else                             //n is odd
//         return ((x%M)*(fastexpo(((x%M)*(x%M))%M,n/2,M)%M))%M;
// }
// ll inverse(ll y,ll M)
// {
// 	return fastexpo(y,M-2,M);
// }
//This power function is very fast (approax 3.5 times than fastexpo) so try to use this function mostly unless some error arrives
int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int powermod(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int imod(int a, int m)
{
    return powermod(a, m - 2, m);
}
// utility function to calculate a%m(means when a is very large)
unsigned int aModM(string s, unsigned int mod) 
{ 
    unsigned int number = 0; 
    for (unsigned int i = 0; i < s.length(); i++) 
    { 
        // (s[i]-'0') gives the digit value and form 
        // the number 
        number = (number*10 + (s[i] - '0')); 
        number %= mod; 
    } 
    return number; 
} 
// log(max(a, b)) is the time complexity to calculate GCD of a and b
int gcd(int a,int b)
{
	if(a==0 || b==0)
	return a+b;
	if(a>b)
	return gcd(a%b,b);
	else
	return gcd(a,b%a);
} 
// isPrime[] : isPrime[i] is true if number is prime  
// prime[] : stores all prime number less than N 
// SPF[] that store smallest prime factor of number 
// [for Exp : smallest prime factor of '8' and '16' 
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ] 
 
//checkpoint-make all vectors present in vector
 
// function generate all prime number less then N in O(n) 
//  vector<int>isprime(MAX_SIZE , true); 
//  vector<int>prime; 
//  vector<int>SPF(MAX_SIZE); 
// void manipulated_seive(int N) 
// {
//     //dont forget to check max_size value and uncomment vectors of prime
//     isprime[0] = isprime[1] = false ; 
//     for (int i=2; i<N ; i++) 
//     { 
 
//         if (isprime[i]) 
//         {
//             prime.push_back(i); 
//             SPF[i] = i; 
//         } 
//         for (int j=0; j < prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++) 
//         { 
//             isprime[i*prime[j]]=false; 
//             SPF[i*prime[j]] = prime[j] ; 
//         } 
//     } 
//     // print all prime number less then N 
//     // for (int i=0; i<prime.size() && prime[i] <= N ; i++) 
//     //     cout << prime[i] << " ";   
// } 
//THis seive is of more time complexicity but it will  take less space for primes till 10^6 and above so prefer this 
//to avoid sigsegv error
// vector<int>prime;
// void SieveOfEratosthenes(int n) 
// { 
//     bool prime2[n+1]; 
//     memset(prime2, true, sizeof(prime2)); 
//   int p;
//     for (p=2; p*p<=n; p++) 
//     { 
//         if (prime2[p] == true) 
//         { 
//             prime.push_back(p);  
//             for (int i=p*p; i<=n; i += p) 
//                 prime2[i] = false; 
//         } 
//     } 
//     for(int i=p;i<=n;i++)
//     if(prime2[i])
//     prime.push_back(i);
  
//     // for(int x:prime)
//     // cout<<x<<" ";
// } 
// int divCount(int n) 
// {  
//     int total = 1; 
//     int z=n;
//     for(auto it=prime.begin();it!=prime.end() && ((*it)*(*it))<=n;it++)
//     {
//         int count = 0; 
//             if (z % (*it) == 0) 
//             { 
//                 while (z % (*it) == 0)
//                 { 
//                     z = z / (*it); 
//                     count++; 
//                 } 
//                 total = total * (count + 1); 
//             }
//             if(z==1)
//             break;
//     }
//     if(z!=1)
//     total*=2;
//     return total;
// }
// int divSumMod(int n,int M) 
// {  
//     int total = 1; 
//     int z=n;
//     for(auto it=prime.begin();it!=prime.end() && ((*it)*(*it))<=n;it++)
//     {
//         int count = 0; 
//             if (z % (*it) == 0) 
//             { 
//                 while (z % (*it) == 0)
//                 { 
//                     z = z / (*it); 
//                     count++; 
//                 } 
//                     int var=(power(*it,count+1)-1)/(*it-1);
//                      var=var%M;
//                      total=(total*var)%M;
//             }
//             if(z==1)
//             break;
//     }
//     if(z!=1)
//     total=(total*((z+1)%M))%M;
//     return total;
// }
// vector<int>fact;
// void factorial(int n)
// {
//     fact.pb(1);
//     fact.pb(1);
//     for(int i=2;i<=n;i++)
//     fact.push_back((fact[i-1]*i)%MOD);
// }
// vector<unsigned int>fact;
// void factorial(unsigned int n)
// {
//     fact.pb(1);
//     fact.pb(1);
//     for(unsigned int i=2;i<=n;i++)
//     fact.pb(fact[i-1]*i);
// }
// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };
// Node *newNode(int data){ 
//     Node *temp = new Node; 
//     temp->data = data; 
//     temp->right = temp->left = NULL; 
//     return temp; 
// }
// void printInorder(Node* node) 
// { 
//     if (node == NULL) 
//         return; 
//     printInorder(node->left); 
//     cout << node->data << " "; 
//     printInorder(node->right); 
// } 
// void printLevelOrder(Node *root)  
// {  
//     if (root == NULL) return;  
//     queue<Node *> q;  
//     q.push(root); 
//     int lvl=1; 
//     while (!q.empty())  
//     {  
//         int nodeCount = q.size();  
//         while (nodeCount > 0) 
//         {  
//             Node *node = q.front();  
//             cout << node->data << " ";  
//             q.pop();  
//             if (node->left != NULL)  
//                 q.push(node->left);  
//             if (node->right != NULL)  
//                 q.push(node->right);  
//             nodeCount--;  
//         }
//         lvl++;
// //checkpoint-If we want to print in line by line then use this else use 2nd  
//         // cout << "\n";
//         //If we want to print in single line then use this one  
//         cout<<" ";
//     }  
// } 
//finding fibonacci no. in O(log(n)) F[0]=0 F[1]=1
// void multiplyfib(int F[2][2], int M[2][2]) 
// { 
//     int x = ((F[0][0] * M[0][0])%MOD + (F[0][1] * M[1][0])%MOD)%MOD; 
//     int y=((F[0][0] * M[0][1])%MOD + (F[0][1] * M[1][1])%MOD)%MOD;
//     int z=((F[1][0] * M[0][0])%MOD + (F[1][1] * M[1][0])%MOD)%MOD;  
//     int w=((F[1][0] * M[0][1])%MOD + (F[1][1] * M[1][1])%MOD)%MOD; 
//     F[0][0] = x; 
//     F[0][1] = y; 
//     F[1][0] = z; 
//     F[1][1] = w; 
// }
// void powerfib(int F[2][2], int n) 
// { 
//     if(n == 0 || n == 1) 
//        return; 
//     int M[2][2] = {{1, 1}, {1, 0}}; 
      
//     powerfib(F, n / 2); 
//     multiplyfib(F, F); 
      
//     if (n & 1) 
//         multiplyfib(F, M); 
// } 
// int fib(int n) 
// { 
//     int F[2][2] = {{1, 1}, {1, 0}}; 
//     if (n == 0) 
//         return 0; 
//     powerfib(F, n - 1); 
//     return F[0][0]; 
// } 
// An AVL tree node  
// class Node  
// {  
//     public: 
//     int key;  
//     Node *left;  
//     Node *right;  
//     int height;  
// };  
// int height(Node *N)  
// {  
//     if (N == NULL)  
//         return 0;  
//     return N->height;  
// }  
// Node* newNode(int key)  
// {  
//     Node* node = new Node(); 
//     node->key = key;  
//     node->left = NULL;  
//     node->right = NULL;  
//     node->height = 1;
//     return(node);  
// } 
// Node *rightRotate(Node *y)  
// {  
//     Node *x = y->left;  
//     Node *T2 = x->right;    
//     x->right = y;  
//     y->left = T2;  
//     y->height = max(height(y->left),height(y->right)) + 1;  
//     x->height = max(height(x->left),height(x->right)) + 1;   
//     return x;  
// }
// Node *leftRotate(Node *x)  
// {  
//     Node *y = x->right;  
//     Node *T2 = y->left;  
//     y->left = x;  
//     x->right = T2;  
//     x->height = max(height(x->left),height(x->right)) + 1;  
//     y->height = max(height(y->left),height(y->right)) + 1;  
//     return y;  
// } 
// int getBalance(Node *N)  
// {  
//     if (N == NULL)  
//         return 0;  
//     return height(N->left) - height(N->right);  
// }  
// Node* insert(Node* node, int key)  
// {  
//     if (node == NULL)  
//         return(newNode(key));  
//     if (key < node->key)  
//         node->left = insert(node->left, key);  
//     else if (key > node->key)  
//         node->right = insert(node->right, key);  
//     else
//         return node;  
//     node->height = 1 + max(height(node->left),height(node->right));  
//     int balance = getBalance(node); 
//     if (balance > 1 && key < node->left->key)  
//     {
//         return rightRotate(node);
//     }
//     if (balance < -1 && key > node->right->key)  
//     {
//             return leftRotate(node);  
//     }
//     if (balance > 1 && key > node->left->key)  
//     {  
//         node->left = leftRotate(node->left);  
//         return rightRotate(node);  
//     }  
//     if (balance < -1 && key < node->right->key)  
//     {  
//         node->right = rightRotate(node->right);  
//         return leftRotate(node);  
//     } 
//     return node;  
// }  
// vector<vector<int>> adj;
//bfs
// int n;
// vector<int>adj[100001];
// // int s;
// vector<bool> used(100001,0);
// vector<int> d(100001,1), p(100001,-1);
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     used[s]=true;
//     p[s]=-1;
//     while(!q.empty())
//     {
//         int v=q.front();
//         q.pop();
//         for(int u:adj[v])
//         {
//             if(!used[u])
//             {
//                 used[u]=true;
//                 q.push(u);
//                 p[u]=v;
//                 d[u]=d[v]+1;
//             }
//         }
//     }
// }
int arr[20];
int n;
bool functor(int i,int sum)
{
    if(sum>=360)
    sum=sum%360;
    if(sum<=(-360))
    sum=360+sum%360;
    if(i==(n+1))
    {
        if(sum==0)
        return true;
        else
        {
            return false;
        }
    }
    return (functor(i+1,sum+arr[i]) || functor(i+1,sum-arr[i]));
}
void myfun()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    if(functor(1,0)==true)
    cout<<"YES"<<"\n";
    else
    {
        cout<<"NO"<<"\n";
    }
} 
signed main()
{
   fastio
    int t=1;
    // cin>>t;
    while(t--)
        myfun();
}
