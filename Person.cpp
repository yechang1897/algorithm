#include "iostream"

struct Person{
    std::string getName()  {return name;}
    std::string getLocaion() {return location;}
    std::string name;
    std::string location;
};

struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s),units_sold(n),revenue(n*p){}
    Sales_data(std::istream &);
    std::string isbn() const {return bookNo;}
    Sales_data& combine (const Sales_data &);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data ::Sales_data(std::istream &is) {//类外构造函数
    // read(is,*this);
}

