/*
1
6 4
1 2 3 3 2 2
7 3 9 1 1 1
*/

#include<bits/stdc++.h>
using namespace std;

struct Basket{
    int type;
    int price;
    Basket(){ this->type = 0; this->price = 0; }
};

int valX(Basket y, int N, int t){
    int v = 0;
    for(int i = 1; i <= N; i++){
        if(y[i].type == t) v += y[i].price;
    }
    return v;
}

int main(){

    int test, N, M;

    cin >> test;

    while(test--){
        cin >> N >> M;
        struct Basket b[N];  int B[N] = {0};

        // N inputs of first line.
        for(int i = 1; i <= N; i++) cin >> b[i].type;

        // N inputs for second one.
        for(int i = 1; i <= N; i++) cin >> b[i].price;

        for(int i = 1; i <= N; i++){
            B[i] = valX(b, N, i);
        }

        for(int i = 1; i <= N; i++) cout << B[i] << " ";
        cout << endl;
    }

	return 0;
}
