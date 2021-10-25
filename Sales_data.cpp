#include "iostream"
class Sales_data{
    friend Sales_data add(const Sales_data&, const Sales_data &);//friend关键字可以使其他类或者函数访问它的非公有成员 称为友元。
    friend std::istream read(std::istream&, Sales_data&);
    friend std::ostream write(std::ostream&, const Sales_data&);
    public:
        Sales_data() = default;
        Sales_data(const std::string &s):bookNo(s){}
        Sales_data(const std::string &s, unsigned n, double p): bookNo(s),units_sold(n),revenue(n*p){}
        Sales_data(std::istream &);
        std::string isbn() const {return bookNo;}
        Sales_data& combine (const Sales_data &);
    private:
        double avg_price() const
        {return units_sold ? revenue/units_sold : 0;}
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::istream read(std::istream&, Sales_data&);
std::ostream write(std::ostream&, const Sales_data&);

class Screen {
    public:
        typedef std::string::size_type pos;
        //usingf pos = std::string::size_type;
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};