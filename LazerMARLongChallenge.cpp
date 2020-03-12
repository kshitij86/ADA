#include<bits/stdc++.h>
using namespace std;


void printer(vector<float> x){
    for(int i = 0; i < x.size(); i++) cout << x[i] << " ";
    cout << endl;
}

// Check the slopes for one query.
int lazerCross(vector<float> slopes, float qSlope){
    int cnt = 0;

    for(int i = 0; i < slopes.size(); i++){
        if(slopes[i] != qSlope)
        cnt ++;
    }
    return cnt;
}

vector<float> slopesMaker(int x[], int N){

}

int main(void){

	int test(0), N(0), Q(0);

    cin >> test;
	while(test--){
		cin >> N >> Q;
		int x[N][2];
        vector<float> v;

		// Take the elements of the array.
		for(int i = 0 ; i < N; i++){
            x[i][0] = i+1;
            cin >> x[i][1];
        }

        for(int i = 0; i < N; i++){
                cout << x[i][0] << " " << x[i][1] << endl;
        }

        for(int i = 0; i < Q; i++){
            // Do the following for each query.
            int x1(0), x2(0), y(0), cnt(0);
            cin >> x1 >> x2 >> y;

        }

    }

	return 0;
}
