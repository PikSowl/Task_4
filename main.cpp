#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;



int main()
{
    //Task was unclear, so this program will work for 0 to 8 inclusive
    cout << "Welcome to Bit Packager 0-8" << endl << "Please, write any numbers from 0 to 8 inclusive" << endl << "Press enter to see writen numbers in backwards order" << endl << "To end program type any letter or 9, and press enter" << endl << endl;
    string inp;
    getline(cin, inp);
    unsigned char il = inp.length();
    for(int i =0; i< il;i++) if(inp[i] > 56 || inp[i] < 48) {
        cout << "wrong input" << endl;
        return 1;
    }

    unsigned char  cl = il / 5;
    if(il%5 == 0) cl--;
    unsigned short ch[cl + 1];

    for(int i = cl; i >= 0; i--)
    {
        ch[i] = 0;
        for(int j = 0; j < 5 && (j  + 5*(cl - i)) < il ; j++)
        {
            ch[i] += (inp[il - j - 1 - 5*(cl - i)] - 48)*(pow(9,j));
        }
    }

    for(int i = 0; i <= cl;i++){
        cout << int(ch[i]) <<" ";
    }
    cout << "That is how they stored" << endl;

    for(int i = 0; i <= cl;i++){
        unsigned short temp = ch[i], firstl = il - 5*cl;
        int decod = 0;

        for(int j = 0; j < 5 &&(j < firstl || i != 0);j++) {
            decod = decod*10 + temp%9 + 1;
            temp /= 9;
        };
        for(int j = 0; j < 5 &&(decod > 0 || i != 0);j++) {
            cout << decod%10 - 1;
            decod /= 10;
        }
    }

    return 0;
}
