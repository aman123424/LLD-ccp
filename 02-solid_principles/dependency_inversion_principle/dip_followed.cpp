#include <iostream>
using namespace std;

// Abstraction / Interface
class Database {
public:
    virtual void save(string user) = 0;
};

//Low-level module
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout<<"Executing SQL Query: INSERT INTO users VALUES='"<<data<<"')"<<endl;
    }
};

// Low-level module
class MongoDatabase : public Database {
public:
    void save(string data) override {
        cout<<"Executing MongoDB function db.users.insert({name: '"<<data<<"'})"<<endl;
    }
};

// High-level module (now loosely coupled with low-level modules)
class UserService {
private:
    Database* db; //Dependency Injection

public:
    UserService(Database* db) {
        this->db = db;
    }

    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    MySQLDatabase sqlDB;
    MongoDatabase mongoDB;

    UserService service1(&sqlDB);
    UserService service2(&mongoDB);

    service1.storeUser("Aman");
    service2.storeUser("Vedant");
}