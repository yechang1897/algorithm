#include<iostream>
#include<algorithm>

using namespace std;
//必须用x把mid保存起来，否则mid会改掉。
void quick_sort(int arr[], int l, int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = arr[l + r >> 1];
    int mid = l + r >> 1;
    // cout << x << " " << arr[mid] << endl;
    while(i < j) {
        do i++ ; while(arr[i] < arr[mid]);
        do j-- ; while(arr[j] > arr[mid]);
        if(i < j) swap(arr[i], arr[j]);
    }
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << i << " " << j << endl;
    quick_sort(arr, l, j),
    quick_sort(arr, j + 1, r);
}

void quick_sort_2(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    cout << i << " " << j << endl;
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
    int arr[] = {49, 59, 88, 37, 98, 97, 68, 54, 31, 3};
    quick_sort(arr, 0, 9);

    for(auto x : arr) {
        cout << x << " ";
    }
    puts("");
    // int arr2[] = {49, 59, 88, 37, 98, 97, 68, 54, 31, 3};
    // quick_sort_2(arr2, 0, 9);

    // for(auto x : arr2) {
    //     cout << x << " ";
    // }
    // puts("");
}