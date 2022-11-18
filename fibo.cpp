#include<bits/stdc++.h>
using namespace std;

void multiply(long long int f[2][2], long long int m[2][2]){
    int mod = pow(10,9)+7;
    long long int x = f[0][0]*m[0][0] + f[0][1]*m[1][0];        
    long long int y = f[0][0]*m[0][1] + f[0][1]*m[1][1];
    long long int z = f[1][0]*m[0][0] + f[1][1]*m[1][0];
    long long int w = f[1][0]*m[0][1] + f[1][1]*m[1][1];  

    f[0][0] = x%mod;
    f[0][1] = y%mod;
    f[1][0] = z%mod;
    f[1][1] = w%mod;     
}

void power(long long int f[2][2], int n){
    if(n==0||n==1)
        return;
    long long int m[2][2] = {{1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);

    if(n%2!=0)
        multiply(f,m);
}

int fibo(int n){
    long long int f[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(f,n-1);
    return f[0][0];
}

int main(){
    int num;
    cout<<"Enter the position: ";
    cin>>num;
    cout<<"\t"<<fibo(num);
    return 0;
}

// Time Complexity : O(2^n)
// int fibonacciNumber(int n){
//     long long int fib=1,n1=1,n2=1;
//     int i,mod=pow(10,9)+7;
//     if(n<=2){
//         return 1;
//     }
//     else{
//         for(i=3;i<=n;i++){
//             fib=n1+n2;
//             fib%=mod;
//             n2=n1;
//             n1=fib;
//         }
//     }

// Time Complexity : O(n)
//     return fib;
//         int i,mod=pow(10,9)+7;
//         long long fib[n+2];
//         fib[0]=0;
//         fib[1]=1;
//         for(i=2;i<=n;i++){
//             fib[i]=fib[i-1]+fib[i-2];
//             fib[i]%=mod;
//         }
//         return fib[n];
// }

// Time Complexity : O(log n)
// void multiply(long long int F[2][2],long long int M[2][2]);
// void power(long long int F[2][2], int n);
// int fibonacciNumber(int n)
// {
//     long long int F[2][2] = {{1, 1}, {1, 0}};
//     if (n == 0)
//         return 0;
//     power(F, n - 1);
//     return F[0][0];
// }

// void power(long long int F[2][2], int n)
// {
//     if(n == 0 || n == 1)
//        return;
//     long long int M[2][2] = {{1, 1}, {1, 0}};
     
//     power(F, n / 2);
//     multiply(F, F);
     
//     if (n % 2 != 0)
//         multiply(F, M);
// }
 
// void multiply(long long int F[2][2],long long int M[2][2])
// {
//     int mod=pow(10,9)+7;
//     long long int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
//     long long int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
//     long long int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
//     long long int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
     
//     F[0][0] = x%mod;
//     F[0][1] = y%mod;
//     F[1][0] = z%mod;
//     F[1][1] = w%mod;
// }