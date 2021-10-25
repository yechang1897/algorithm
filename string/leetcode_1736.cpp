#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

string maximumTime(string time) {
   if(time[0] == '?') {
       if('4' <= time[1] && time[1] <= '9') {
           time[0] = '1';
       } else {
           time[0] = '2';
       }
   }
   if(time[1] == '?') {
       if(time[0] == '2') {
           time[1] = '3';
       } else {
           time[1] = '9';
       }
   }
   if(time[3] == '?') {
       time[3] = '5';
   }
   if(time[4] == '?') {
       time[4] = '9';
   }
   return time;
}

int main() {
    string time = "??:3?";
    cout << maximumTime(time);
}