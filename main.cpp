#include <iostream>
#include <Vector>
#include <stdlib.h>
#include <time.h>
#include <QTime>

using namespace std;

void Shoar(vector<int> &arr, int left, int right);

void Smerge (vector<int> &arr, int left, int right, int num);

void Sbubble (vector<int> &arr, int num);

void copy (vector<int> arr, vector<int> &arr_temp, int num);


int main()
{
    srand(time(0));

    vector<int> arr;

    int num=10000;

    for (int i=0; i<num; i++)

    {
        int temp=rand()%21;

        arr.push_back(temp);
    }

    vector<int> arr_temp;

    arr_temp.resize(num);


    copy(arr, arr_temp, num);

    QTime Tbubble;

    Tbubble.start();

    Sbubble(arr_temp, num);

    int t_bubble=Tbubble.elapsed();

    cout<<"bubble time"<<t_bubble<<endl;

    copy(arr, arr_temp, num);

    QTime Thoar;

    Thoar.start();

    Shoar(arr_temp, 0, num-1);

    int t_hoar=Thoar.elapsed();

    cout<<"hoar time"<<t_hoar<<endl;

    copy(arr, arr_temp, num);

    QTime Tmerge;

    Tmerge.start();

    Smerge(arr_temp, 0, num-1, num);

    int t_merge=Tmerge.elapsed();

    cout<<"merge time"<<t_merge<<endl;

    copy(arr, arr_temp, num);

    QTime Tsort;

    Tsort.start();

    sort(arr_temp.begin(), arr_temp.begin()+num);

    int t_sort=Tsort.elapsed();

    cout<<"standart time"<<t_sort<<endl;


    return 0;
}

void Sbubble (vector<int> &arr, int num)
{
    for (int i=0; i<num-1; i++)

        for (int j=0; j<num-i-1; j++)

            if (arr[j]>arr[j+1])

                    swap(arr[j], arr[j+1]);
}

void Shoar(vector<int> &arr, int left, int right)
{
    int i=left;

    int j=right;

    int middle=(left+right+1)/2;

    do

    {
        while(arr[i]<arr[middle]) i++;

        while(arr[j]>arr[middle]) j--;

        if (i<=j)
        {
            swap(arr[i], arr[j]);

            i++;

            j--;
        }
    }
    while (i<=j);

    if (i<right) Shoar(arr, i, right);

    if (left<j) Shoar(arr, left, j);
}

void Smerge (vector<int> &arr, int left, int right, int num)
{
    if (left==right) return;

    if (right-left==1)

    {
        if (arr[left]>arr[right])

            swap(arr[left], arr[right]);

        return;
    }
    int mid=(left+right)/2;

    Smerge(arr, left, mid, num);

    Smerge(arr, mid+1, right, num);

    vector<int> arr_temp;

    arr_temp.resize(num);

    int _left=left;

    int _right=mid+1;

    int cur=0;

    while (right-left+1 != cur)

    {
        if (_left>mid)

            arr_temp[cur++]=arr[_right++];

        else if (_right>right)

            arr_temp[cur++]=arr[_left++];

        else if (arr[_left]>arr[_right])

            arr_temp[cur++]=arr[_right++];

        else arr_temp[cur++]=arr[_left++];
    }
    for (int i=0; i<cur; i++)

        arr[i+left]=arr_temp[i];
}

void copy (vector<int> arr, vector<int> &arr_temp, int num)
{
    for (int i=0; i<num; i++)

        arr_temp[i]=arr[i];
}
