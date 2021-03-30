#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int ans = 0;
    while(n>0){
        int lastDigit = n%10;
        ans = ans*10 + lastDigit;
        n/=10;
    }
    return ans;
}

int addBinary(int a, int c){
    int ans = 0;
    int prevCarry = 0;
    while(a>0 && c>0){
        if(a%2 == 0 && c%2 == 0){
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        else if((a%2 == 0 && c%2 == 1) || (a%2 == 1 % c%2 == 0)){
            if(prevCarry == 1){
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }

        }
        else{
            ans = ans*10 + prevCarry;
            prevCarry = 1;
        }
        a/=10;
        c/=10;
    }

    while(a>0){
        if(prevCarry == 1){
            ans = ans*10 + 0;
            prevCarry = 1;
        }
        else{
            ans = ans*10 + 1;
            prevCarry = 0;
        }
    }
    while(a>0){
        if(prevCarry == 1){
            if(a%2 == 1){
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + (a%2);
        }
        a/=10;

    }

     while(c>0){
        if(prevCarry == 1){
            if(c%2 == 1){
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + (c%2);
        }
        c/=10;
    }
    if(prevCarry == 1){
        ans = ans*10 + 1;
    }
    ans = reverse(ans);
    return ans;
}


int32_t main(){

int a,c;
cin >> a >> c;

cout << addBinary(a,c) <<endl;

}