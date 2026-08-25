//Here SaveToDB class violates the open-close principle as when we need to add a new saving method, we need to change the exisiting code in the class.
#include <iostream>

using namespace std;

class SaveToDB {
    public:
        SaveToDB() {

        }

        void saveToSQLDB() {
            cout << "Saving the shopping cart to SQLDB..."  << endl;
        }

        void saveToNoSQLDB() {
            cout << "Saving the shopping cart to NoSQLDB..."  << endl;
        }

        void saveToFile() {
            cout << "Saving the shopping cart to File..." << endl;
        }
};

int main() {
    SaveToDB* save = new SaveToDB();
    
    save->saveToNoSQLDB();

    save->saveToSQLDB();

    save->saveToFile();

    return 0;
}