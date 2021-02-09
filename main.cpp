#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>


using namespace std; // only for 

int random_number(int max_num) {
    int random_num;

    srand(time(0));
    random_num = (rand() % max_num) + 1;

    return random_num;
}

bool find_word() {
    return false;
}

bool display_word() {
    return true;
}

int main() {
    ofstream fout;
    ifstream fin;
    int x;
    char sum[10];

    // open a file
    fin.open("100_words.fic", ios::binary|ios::in);

    char the_string[128];
    int lenOfString;
    int counter = 0;
    char *master_list[100];
    int random_num;

    while(!fin.eof()) {
        fin >> the_string;
        cout << the_string << endl;
        master_list[counter] = the_string;

        // all 100 words stored in master_list
        counter++;
    }
    fin.close();

    cout << "\n" << "THE LIST: " << "\n"<< endl;

    for (int n=0; n < counter + 1; n++) {
        cout << master_list[n] << endl;
    }

    // randomly select a word from master_list
    random_num = random_number(100);

    //random_word = master_list[random_num];
    
    //char[15] selected_word = selected_word()

    // scramble the word

    // show the scrambled word

    // user can guess the word

    // ask user if they want to continue
    return 0;


}