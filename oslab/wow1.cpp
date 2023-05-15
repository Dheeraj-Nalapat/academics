// find the biggest sum of consecutive numbers in a given array

#include <iostream>
using namespace std;

int main()
{
    int n,m, i, j, k, sum, maxsum = 0,point=-1;
    cin >> n;
    cin >>m;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n-m+1; i++)
    {
        sum = 0;
        for (j = i; j < m+i; j++)
        {
            sum += a[j];
        }
        cout<<"sum="<<sum<<endl;
        if (sum > maxsum)
            {
                maxsum = sum;
                point = i;
            }
    }
    cout<<"     \n";
    for(int j=0;j<n;++j){
        cout<<a[j]<<" ";
    }

    cout<<"\n";

    cout << maxsum << " " << point;
    return 0;
}


