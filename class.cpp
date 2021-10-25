#include"class.h"
#include<cstring>
String::String(const char* p=0){
    if(p){
        data = new char[strlen(p)+1];
        strcpy(data,p);
    }
    else{
        data = new char[1];
        data[0] = '\0';
    }
    
}