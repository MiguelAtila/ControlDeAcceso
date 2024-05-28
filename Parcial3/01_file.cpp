// Basic file operation
#include <iostream>
#include <fstream>
using namespace std;

int main (){
    ofstream myfile;

    myfile.open ("Example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();

    return 0;
}