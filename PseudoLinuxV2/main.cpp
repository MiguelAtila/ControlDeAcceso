#include <iostream>
#include <list>
using namespace std;

struct Users{
    string User;
    list<string> Files;
};

int main()
{
    list<Users> users;
    Users user;

    user.User = "Hola";
    users.push_back(user);

    user.User = "Adios";
    users.push_back(user);

    for (auto i : users){
    cout << i.User << ' ';
    }

    return 0;
}
