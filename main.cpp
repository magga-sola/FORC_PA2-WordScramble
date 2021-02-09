#include <iostream>
#include <fstream>
#include <string.h>

using namespace std; // only for 
int main() {
    ofstream fout;
    ifstream fin;
    int x;
    char sum[10];
    int random_number;
    int strLen = 0;
    
    FILE* prt = fopen("word_list.fic", "r");

    // open a file
    fin.open("word_list.fic", ios::binary | ios::in);

    char the_string[128];

    while (!fin.eof()) {
        fin >> the_string;
        int temp = strlen(the_string);
        if (temp > strLen) {
            strLen = temp;
        }

        //cout << the_string << " " << strLen << endl;
    }
    cout << strLen << endl;
    int strlens = strlen(the_string);
    fin.close();
    //char hello = new char[strlens];

    /*cout << "\n" << "THE LIST: " << "\n"<< endl;

    for (int n=0; n < counter; n++) {
        cout << master_list[n] << endl;
    }

    // randomly select a word from master_list
    random_num = random_number(100);*/

    char theWord[strLen];
    fscanf(prt, "%s", theWord);
    cout << theWord << " Hello besties" << endl;
    random_number = rand() % strLen;
    cout << random_number;
    cout << the_string[random_number];
    cout << the_string;
    //strcpy(hello, the_string[random_number]);
    //cout << hello << endl;

    //random_word = master_list[random_num];

    //char[15] selected_word = selected_word()

    // scramble the word

    // show the scrambled word

    // user can guess the word

    // ask user if they want to continue
    return 0;


}