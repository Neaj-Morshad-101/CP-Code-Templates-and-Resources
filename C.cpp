// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///constants
const ll mxn = 200200;
const int mod = 1000000007;//1e9+7;

#define endl '\n'
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl

void print(bool ok)
{
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}


///program starts...........

int tc;


// Selection Sort



// iteration
// 0: 30, 10, 15, 11, 14
// p = 0, min_idx = 1 swap(0, 1) swap(30, 10)
// 1: 10 30 15 11 14 fixing 0th element

// 2: 0 1 5 3 4 fixing 1st element
// 3: 0 1 3 5 4
// 4: 0 1 3 4 5


// 0 1 3 4 5 (accending order)

void selection_sort(int arr[], int n)
{
    for (int p = 0; p < n; p++)
    {
        //find the min of the rest of the array
        //and swap it with the element at position p

        int min_idx = p;

        //finding the minimum element's index
        for (int rest = p + 1; rest < n; rest++)
        {
            if (arr[rest] < arr[min_idx])
            {
                //update the min_idx
                min_idx = rest;
            }
        }

        watch2(p, min_idx);

        swap(arr[p], arr[min_idx]);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << endl;

        //implement swap

    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[5] = {30, 10, 15, 11, 14};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // arr[0] = 3;
    // arr[1] = 0;


    selection_sort(arr, 5);

    return 0;
}

