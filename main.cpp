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


int main() {
    ofstream fout;
    ifstream fin;
    int x;
    char sum[10];

    // open a file
<<<<<<< HEAD
    fin.open("100_words.fic", ios::binary | ios::in);
=======
    fin.open("100_words.fic", ios::binary|ios::in);
>>>>>>> main

    char the_string[30];
    int lenOfString;
    int counter = 0;
    char master_list[100][30];
    int random_num;
    char random_word[30];

    while (!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly select a word from master_list
    random_num = random_number(100);

    strcpy(random_word, master_list[random_num]);
    cout << random_word << endl;

<<<<<<< HEAD
=======


>>>>>>> main
    // scramble the word
    //word_scrambler(random_word);

    // show the scrambled word
    //display_word(random_word);

    // user can guess the word
    //play();

    // ask user if they want to continue
    return 0;


}