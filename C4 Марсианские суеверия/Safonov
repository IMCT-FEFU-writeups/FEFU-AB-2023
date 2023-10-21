#include<iostream>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int n, m, k, answer = 0, cel, ost, k1;
    cin >> n >> m >> k;
    k1 = k;
    if (k >= 4 && k < 13)
        k = k - 1;
    if (k >= 13)
        k = k - 2;
    cel = k / m;
    ost = k % m;
    if (n * m < k || k1 == 4 || k1 == 13)
        answer = -1;
    else{
        if (cel >= 13){
            if (ost != 0)
                answer = cel + 3;
            else 
                answer = cel + 2;
        }
        if (cel < 13 && cel >= 4){
            if (ost != 0){
                if (cel + 1 != 13)
                    answer = cel + 2;
                if (cel + 1 == 13)
                    answer = cel + 3;
            }
            if (ost == 0)
                answer = cel + 1;
        }
        if (cel < 4){
            if (ost != 0){
                if (cel + 1 != 4)
                    answer = cel + 1;
                if (cel + 1 == 4)
                    answer = cel + 2;
            }
            if (ost == 0)
                answer = cel;
        }
    }
    
    
    cout << answer;
    
    
    
    
    return 0;
} 
