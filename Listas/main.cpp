#include <iostream>
#include <list>

using namespace std;

int main() {
    // defined list
    list<int> gqlist{12, 45, 8, 6};

        gqlist.push_back(99);
        gqlist.push_front(0);
        gqlist.pop_back();
        gqlist.pop_front();

    for (auto i : gqlist) {
        cout << i << ' ';
    }
    return 0;
}
