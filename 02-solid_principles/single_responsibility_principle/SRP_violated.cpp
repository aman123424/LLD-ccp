// In this file we will see a class violating the SRP

#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    int price;

    Product(string name, int price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
    private:
        vector<Product*> products;
    
    public:
        void addProduct(Product* product) {
            products.push_back(product);
        }

        const vector<Product*>& getProducts() {
            return products;
        }

        // 1. Calculates the total price of the products in the cart
        int calculateTotalPrice() {
            int total = 0;
            for(auto product : products) {
                total += product->price;
            }
            return total;
        }
        
        // 2. Prints Invoice - Violates SRP, this should be in separate class
        void printInvoice() {
            cout << "Shopping Cart Invoice" << endl;
            for(auto p : products) {
                cout << p->name << ": $" << p->price << endl;
            }
            cout<< "Total Amount: $" << calculateTotalPrice() << endl;
        }

        // 3. Saves to DB - Violates SRP, this should be in separate class
        void saveToDB() {
            cout << "Saving Shopping Cart to database..." << endl;
        }
};

int main () {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 93700));
    cart->addProduct(new Product("Laptop Stand", 500));
    cart->addProduct(new Product("Pen Drive", 1250));

    cart->printInvoice();

}