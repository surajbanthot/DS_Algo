#include <iostream>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace std;

bool f(int x, int y)
{
    return x > y;
}

int main()
{
    //C++ STL
    vector<int> A = {11, 2, 3, 4};
    // cout<<A[1]<<endl;

    sort(A.begin(), A.end()); //O(NlogN)

    for (auto x : A)
        cout << x << endl;

    cout << "**********\n";

    // bool present =binary_search(A.begin(),A.end(),3);

    // if(present)cout<<"present";

    A.push_back(100);

    for (auto x : A)
        cout << x << endl;

    A.push_back(100);
    A.push_back(123);

    //2,3,4,11,100,100,123

    vector<int>::iterator itrlower = lower_bound(A.begin(), A.end(), 100); // Gives the first element >= to the specified
    vector<int>::iterator itrupper = upper_bound(A.begin(), A.end(), 100); // Gives the first element > to the specified
    cout << "lower_bound" << *itrlower << endl;
    cout << "upper_bound" << *itrupper << endl;

    cout << itrupper - itrlower << endl;

    sort(A.begin(), A.end(), f);
    return 0;
}