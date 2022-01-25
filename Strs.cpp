#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int cmp(char* s1, char*s2) {//s1 - s2
    if(*s1 == 0)
        return -*s2;
    if(*s2 == 0)
        return *s1;

    if(*s1 == *s2)
        return cmp(s1++, s2++);
    
    return *s1 - *s2;
}


int main() {

    char str[256];
    cout << "Type string\n";
    cin.getline(str, 256);
    strcmp;//compare
    strlen;//length
    strcat;//concatination
    strcpy;//copy
    /*for(int i = 0; i < 256; i++) {
        cout << (int)str[i] << ' ';
    }*/
    strcat(str, "asdf");
    cout << str << '\n';
    /*isalpha;
    isdigit;
    isspace;
    islower;
    toupper;
*/
    ifstream fin("Smth.txt");
    fin >> str;
    cout << str;
    fin.eof();//end of file

    fin.seekg(0, ios::end);//смещает в позицию конца
    int n = fin.tellg();//говорит номер текущей позиции
    char* str2 = new char[n + 1];
    fin.seekg(0, ios::beg);
    fin.read(str2, n);
    str2[n] = '\0';
    cout << str2 << '\n';
}