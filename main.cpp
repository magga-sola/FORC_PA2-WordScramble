#include <iostream>
#include <fstream>
#include <string.h>

using namespace std; // only for 
int main() {
    ofstream fout;
    ifstream fin;
    int x;
    char sum[10];

    // open a file
    fin.open("word_list.fic", ios::binary|ios::in);

    char the_string[128];

    while(!fin.eof()) {
        fin >> the_string;
        int strLen = strlen(the_string);
        cout << the_string << " " << strLen << endl;
    }
    fin.close();

    // randomly select a word from the file
    // scramble the word

    // show the scrambled word

    // user can guess the word

    // ask user if they want to continue
    return 0;


}