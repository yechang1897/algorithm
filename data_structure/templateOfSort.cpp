#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
1 冒泡排序
比较相邻元素，将大的数往后移，这样一次操作就将大的数移到了后面。
时间复杂度为O(n2)
稳定排序


优化操作，设置一个flag,一次遍历后如果数据都没发生移动，则可以停止
*/
void bubble_sort(vector<int>& nums) {
    for(int i = nums.size() - 1; i >= 0; i--) {
        bool flag = true;
        for(int j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                flag = false;
            }
        }
        if(flag) break;
    }
}

/*
2.选择排序
找到最小的元素，然后与队列开头交换一下。这个算法和冒泡差别不大，就是减少了交换的次数，每次遍历最多只交换一次。
时间复杂度为O(N2)
不稳定
*/

void select_sort(vector<int>& nums) {
    for(int i = 0;i < nums.size(); i++) {
        int idx = i;
        for(int j = i + 1; j < (int)nums.size(); j++) {
            if(nums[j] < nums[idx]) idx = j;
        }
        if(idx != i) swap(nums[idx], nums[i]);
    }
}

/*
3.插入排序
从后往前找，如果当前的数大于我们要插入的数，就将当前的数往后移一位。
（1）最坏的时间复杂度为O(n2),就是所有的数都是倒序排列，每插入一个数都有移动全部的数
（2）最好的情况是O(N),所有的数都是从小到大排列，不需要移动数组。
稳定性：稳定
*/

void insert_sort(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++) {
        int t = nums[i], j;
        for(j = i - 1;j >= 0; j--) {
            if(nums[j] > t) swap(nums[j], nums[j + 1]);
            else break;
        }
        //加不加都不影响效果，可能是为了稳定行
        nums[j + 1] = t;
    }
}
/*
希尔排序
*/
int incrgap = 3;
void shell_sort(vector<int>& nums) {
    int t = 0;
    int len = nums.size();
    int gap = len / incrgap + 1;
    while(gap) {
        for(int i = gap; i < len; i++) {
            t = nums[i];
            int j = i;
            while(j >= gap && t < nums[j - gap]) {
                swap(nums[j], nums[j - gap]);
                j -= gap;
            }
            nums[j] = t;
        }
        gap /= incrgap;
    }
}

/*
5 归并排序
分治，自顶向下，递归的做法，自低向上，循环（力扣上148题）
时间复杂度O(Nlg(N)).
空间复杂度：O（LgN）+O(N)
*/
// vector<int> t;
void merge_sort(vector<int>& nums, int l, int r) {
    if(l >= r) 
        return;
    int mid = l + r >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> t; 
    t.clear();
    while(i <= mid && j <= r) {
        if(nums[i] <= nums[j]) {
            t.push_back(nums[i]);
            i++;
        } else {
            t.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        t.push_back(nums[i]);
        i++;
    }

    while(j <= r) {
        t.push_back(nums[j]);
        j++;
    }

    for(int i = l, k = 0;i <= r;i++) nums[i] = t[k++];
}

/*
利用归并排序求逆序对？
*/

int merge_sort_2(vector<int>&nums, int l, int r) {
    if(l >= r) return 0;
    int res = 0;
    int mid = l + r >> 1;
    res += merge_sort_2(nums, l, mid);
    res += merge_sort_2(nums, mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> t; 
    t.clear();
    while(i <= mid && j <= r) {
        if(nums[i] <= nums[j]) {
            t.push_back(nums[i]);
            i++;
        } else {
            res += (mid - i + 1);
            t.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        t.push_back(nums[i]);
        i++;
    }

    while(j <= r) {
        t.push_back(nums[j]);
        j++;
    }

    for(int i = l, k = 0;i <= r;i++) nums[i] = t[k++];
    return res;
}
/*
6 快速排序
从整个数列中随机挑一个数，将数列中大于这个数放到右边，小于这个数的放到左边。
平均时间复杂度为O(Nlg(N))
空间复杂度为lg（N）,不稳定

最坏时间复杂度为O(N2)。就是第一次选的 分界值使得左边一个没有，都在右边，
第二次也是，这样的话，会递归N层，每次都要进行（O(N)的遍历。
*/

void quick_sort(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int t = nums[l + r >> 1];
    int i = l - 1, j = r + 1;
    while(i < j) {
        do(i++);while(nums[i] < t);
        do(j--);while(nums[j] > t);
        if(i < j) swap(nums[i], nums[j]);
    }
    // for(auto x : nums) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << i << " " << j <<endl;    
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

void quick_sort_2(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int t = nums[l];
    int i = l, j = r;
    while(i < j) {
        while(nums[j] >= t && i < j) j--;
        while(nums[i] <= t && i < j) i++;       
        if(i < j) swap(nums[i], nums[j]);
    }
    // cout << l << " " << r << " " << i  << " " << j << endl;
    swap(nums[l], nums[i]);
    for(auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
    cout << i << " " << j <<endl;
    quick_sort_2(nums, l, i - 1);
    quick_sort_2(nums, i + 1, r);
}

//快速排序（从小到大）
void quick_sort_3(int left, int right, vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	//基准数归位
	swap(arr[left], arr[i]);
	quick_sort_3(left, i - 1, arr);//递归左边
	quick_sort_3(i + 1, right, arr);//递归右边
}

/*
7 堆排序
基于完全二叉树的数据结构。完全二叉树是指只有最后一层可以是不饱满的，
而且根节点的值是大（小）于左右儿子。
不稳定排序
*/

void push_down(vector<int>& nums, int size, int u) {
    int t = u, l = u * 2, r = u * 2 + 1;
    if(l < size && nums[l] > nums[t]) t = l;
    if(l < size && nums[r] > nums[t]) t = r;
    if(t != u) {
        swap(nums[t], nums[u]);
        push_down(nums, size, t);
    }
}

void push_up(vector<int>&heap,int  u)
{
    while(u/2&&heap[u/2]<heap[u])
    {
        swap(heap[u/2],heap[u]);
        u/=2;
    }
}

void insert(vector<int>& nums ,int size ,int x) {
    nums[++size] = x;
    push_up(nums, x);
}

void remove_head(vector<int>& nums, int size, int u) {
    nums[1]=nums[size];
    size--;
    push_down(nums,size,1);
}


void heap_sort(vector<int>& nums, int n) {
    int size = n;
    for(int i = 1; i <= n; i++ )   push_up(nums, i);
    for(int i = 1; i <= n; i++) {
        swap(nums[1], nums[size]);
        size --;
        push_down(nums, size, 1);
    }
}

/*
8 计数代码（线性时间复杂度，前提是数据范围与数的个数大致相同，比如10e7个数，每个数的范围为0-10e7）
*/

void count_sort(vector<int>& nums, int n) {
    vector<int> cnt(101, 0);
    for(auto x : nums) cnt[x]++;
    for(int i = 0, j = 0; i < n; i++){
        while(cnt[i]) {
            nums[j++] = i;
            cnt[i]--;
        }
    }
}
/*
9.桶排序：反应了一种思想，计数排序的升级
比如说数很多，0-20亿数据，那么我们可以搞个1000个，那么每个桶里面的数就有2000000个数
那么 【0，1999999】【2000000，3999999】。。。
那么桶内部的就可以使用任何的排序方式。


10.基数排序：按各个位进行排序。先将每个数按照每个位上的数放入，这样我们只需要10个桶，然后再将桶中的数
写回原数组，这样将所有的位数遍历完，数组就排好序了
*/

int get(int x, int i){
    while(i--) x /= 10;
    return x % 10;
}

void radix_sort(vector<int>& nums, int n) {
    vector<vector<int>> cnt(10);
    //位数最大位4位
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 10; j++) cnt[j].clear();

        for(int j = 0; j < n; j++) {
            cnt[get(nums[j], i)].push_back(nums[j]);
        }
        
        for(int j = 0, k = 0; j < 10; j++) {
            for(int x : cnt[j]) {
                nums[k++] = x;
            }
        }
        for(auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int m = (1 + 2, 2 + 1, 3 + 1);

int main() {
    // vector<int> nums = {301, 211, 1111, 521, 3213, 1011, 3222, 7111, 6111, 7111, 119, 1118, 1111};
    // vector<int> heap = {0, 3, 2, 1, 5, 3, 10, 3, 7, 6, 7, 9, 8, 1};
    // vector<int> nums2 = {49, 59, 88, 37, 98, 97, 68, 54, 31, 3};

    // bubble_sort(nums);
    // insert_sort(nums);
    // shell_sort(nums);
    // merge_sort(nums);
    // cout << merge_sort_2(nums, 0, nums.size() - 1) << endl;
    //quick_sort(nums2, 0, nums2.size() - 1);
    // quick_sort_2(nums, 0, nums.size() - 1);
    // quick_sort_3(0, nums.size() - 1, nums);
    // heap_sort(heap, heap.size());
    // count_sort(nums, 13);
    // radix_sort(nums, nums.size());
    //for(auto x : nums2)
    //    cout << x << " ";
    cout << m << endl;
}