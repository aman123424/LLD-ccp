// OCP followed as we have created different classes now for different databases, and when we want to add a new DB type, or save type, we don't need to add new code to the exisiting classes and just have to create a new class inheriting from the base class SaveToDB, so the code is closed for modification but at the same time open for extension.

#include <iostream>

using namespace std;

class SaveToDB
{
public:
    virtual void save() = 0;
};

class SaveToNoSQLDB : public SaveToDB
{
public:
    void save() override
    {
        cout << "Saving the shopping cart to NoSQLDB..." << endl;
    }
};

class SaveToSQLDB : public SaveToDB
{
public:
    void save() override
    {
        cout << "Saving the shopping cart to SQLDB..." << endl;
    }
};

class SaveToFile : public SaveToDB
{
public:
    void save() override
    {
        cout << "Saving the shopping cart to File..." << endl;
    }
};

int main()
{
    SaveToDB *file = new SaveToFile();
    SaveToDB *sqldb = new SaveToSQLDB();
    SaveToDB *nosqldb = new SaveToNoSQLDB();

    file->save();
    sqldb->save();
    nosqldb->save();
}