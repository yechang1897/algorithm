#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


//  预先构建一些数组 0-19
string special[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", \
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
// 十位数
string tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
// 千位数，百万位，十亿
string throusands[4] = {"", "Thousand", "Million", "Billion"};

// 解决三维数字
string helper(int num)
{
    // cout << num << endl;
    if (num < 20)
    {
        return special[num];
    }
    else if (num >= 20 && num <= 99)
    {
        // 构建 Thrity One
        return tens[num/10] + (num%10 != 0 ? (" " + special[num%10]): "");
    }
    else
    {
        string one = helper(num%100);
        // cout << "[" << one << "]" << endl;
        return special[num/100] + " Hundred" + (one != "" ? (" " + one) : "");
    }
}


string numberToWords(int num) {
    // 考虑边缘情况
    if (num == 0)
    {
        return "Zero";
    }

    string res = "";
    // 倒序来排列
    int index = 0;
    while (num > 0)
    {
        // 忽略能完全能整除的情况
        if (num % 1000 > 0)
        {
            if (index == 0)
            {
                res = helper(num % 1000);
            }
            else
            {
                res = helper(num % 1000) + " " + throusands[index] + (res != "" ? (" " + res) : "");
            }
        }
        num /= 1000;
        ++index;
    }
    return res;
}

string helper2(int num) {
    if(num <= 19) {
        return special[num];
    } else if(num <= 99 && num > 19) {
        return tens[num / 10] + " " + special[num % 10];
    } else {
        string ones = helper(num % 100);
        return special[(num / 100)] + " Hundred " + (ones != "" ? (" " + ones) : "");; 
    }
}

string numberToWords2(int num) {
    string res = "";
    int index = 0;
    while(num) {
        if(index) {
            res =  helper(num % 1000) +  " " + throusands[index]  +  " " + res;                
        } else {
            res =  helper(num % 1000);              
        }
        num /= 1000;
        index++;  
    }
    return res;
}



int main() {
    int num = 100;
    cout << "1"<<helper2(num%100) << "1"<<endl;
    cout << numberToWords2(num);
}