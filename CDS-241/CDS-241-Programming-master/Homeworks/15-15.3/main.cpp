#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quote {
public:
    Quote() = default; // = default see § 7.1.4 (p. 264)
    Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
// returns the total sales price for the specified number of items
// derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual ~Quote() = default; // dynamic binding for the destructor
    virtual void debug() {
        cout << bookNo << ", price: " << price << endl;
    }
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};

class Bulk_quote : public Quote { // Bulk_quote inherits from Quote
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p,
        std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) { };
    // as before
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t cnt) const
    {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    void debug() override { cout << isbn() << ", price: " << price << ", discount: " << discount << ", min_qty: " << min_qty << endl; }
private:
    std::size_t min_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0; // fractional discount to apply
};

class too_much_quote : public Quote {
    too_much_quote() = default;
    too_much_quote(const std::string& book, double p,
        std::size_t qty, double disc) :
        Quote(book, p), max_qty(qty), discount(disc) { };
    // as before
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t cnt) const
    {
        if (cnt < max_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    std::size_t max_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0; // fractional discount to apply
};


int main(int, char**) {
    //2
    /*
        Protected variables inside a base class allow subclasses to access
        them as if they were its own variables. This cannot happen with private,
        as they are restricted to the class itself. Protected stays within the hierarchy.
    */

    //7 see too_much_quote above

    //8
    /*
        Static type is when you define a variable, it will have a static (unchanging)
        type of object that it can hold. For example, a Quote q; can hold any object of type quote.
        Dynamic type is being able to put either a Quote or Bulk_quote inside Quote q, and when
        we use q, the dynamic portion will figure out which class we need to call the methods from.
    */

    //11 done
}
