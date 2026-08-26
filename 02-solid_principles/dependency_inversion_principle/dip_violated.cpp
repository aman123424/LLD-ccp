// In the example below, the high level module (UserService class) which talks to client (main function) directly depends on the low-level modules (SQL and Mongo classes)

#include <iostream>
using namespace std;

class MySQLDb { // Low level module
public:
    void saveToSQL(string data) {
        cout<<"Executing SQL query: INSERT INTO users VALUES('" << data<<"');"<<endl;
    }
};

class MongoDB { // Low level module
public:
    void saveToMongo(string data) {
        cout<<"Executing MongoDB function db.users.insert({name: '"<<data<<"'})"<<endl;
    }
};

class UserService { //High Level module, tightly coupled with low level modules
private:
    MySQLDb* sql; // Direct dependency on MySQLDb class
    MongoDB* mongo; // Direct dependency on MongoDB class

public:
    void storeUserToSQL(string user) {
        sql->saveToSQL(user);
    }

    void storeUserToMongo(string user) {
        mongo->saveToMongo(user);
    }
};

int main() {
    UserService userService;

    userService.storeUserToMongo("Aman");
    userService.storeUserToSQL("Vedant");
}