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

<<<<<<< Updated upstream
    // randomly select a word from the file
=======
    cout << "\n" << "THE LIST: " << "\n"<< endl;

    for (int n=0; n < counter; n++) {
        cout << master_list[n] << endl;
    }

    // randomly select a word from master_list
    random_num = random_number(100);

    //random_word = master_list[random_num];
    
    //char[15] selected_word = selected_word()

>>>>>>> Stashed changes
    // scramble the word

    // show the scrambled word

    // user can guess the word

    // ask user if they want to continue
    return 0;


}