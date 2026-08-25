#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string name;
    int price;

    Product(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};

// Only responsible for the cart related business logic
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    const vector<Product *> &getProducts()
    {
        return products;
    }

    // 1. Calculates the total price of the products in the cart
    int calculateTotalPrice()
    {
        int total = 0;
        for (auto product : products)
        {
            total += product->price;
        }
        return total;
    }
};

// Responsible for printing invoice
class CartInvoicePrinter
{
private:
    ShoppingCart *cart;

public:
    CartInvoicePrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        cout << "Shopping Cart Invoice" << endl;
        vector<Product *> products = cart->getProducts();
        for (auto p : products)
        {
            cout << p->name << ": $" << p->price << endl;
        }
        cout << "Total Amount: $" << cart->calculateTotalPrice() << endl;
    }
};

// Responsilble for saving to database
class SaveCartToDB
{
private:
    ShoppingCart *cart;

public:
    SaveCartToDB(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void saveToDB()
    {
        cout << "Saving Shopping Cart to database..." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 93700));
    cart->addProduct(new Product("Laptop Stand", 500));
    cart->addProduct(new Product("Pen Drive", 1250));

    CartInvoicePrinter *printer = new CartInvoicePrinter(cart);
    printer->printInvoice();
}