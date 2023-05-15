// to find the index were the net diffrence between the avrerage of the numbers till the index and the index is the smallest.

#include <iostream>
using namespace std;

int  main(){
    int n,m, i, j, k, sum, maxsum1 = 0,point=-1,maxsum2=0,avg1,avg2,low=100000;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        maxsum1 += a[i];
    }
    j = n;
    k=0;
    for(i=0;i<n;i++){
        j-=1;
        k+=1;
        maxsum1 -= a[i];
        maxsum2 += a[j];
        avg1 = maxsum1/j;
        avg2 = maxsum1/k;
        cout<<"avg1="<<avg1<<" avg2="<<avg2<<endl;
        if(abs(avg1-avg2)<low){
            low =abs(avg1-avg2);
            cout<<"low="<<low<<endl;
            point = k;
            cout<<"point="<<point<<endl;
        }
    }
    
    cout<<" the point is ";
    return 0;
}