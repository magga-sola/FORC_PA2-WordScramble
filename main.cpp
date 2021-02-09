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

    char the_string[30];
    int lenOfString;
    int counter = 0;
    char master_list[100][30];
    int random_num;

    while(!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly select a word from master_list
    random_num = random_number(100);

    cout << master_list[random_num] << endl;

    
    //char[15] selected_word = selected_word()

    // scramble the word

    // show the scrambled word

    // user can guess the word

    // ask user if they want to continue
    return 0;


}