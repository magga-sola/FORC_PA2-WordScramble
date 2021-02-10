#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>


using namespace std; // only for 

bool random_function(int max_num, char word[], char master_list[][30]) {
    int random_num;

    srand(time(0));
    random_num = (rand() % max_num) + 1;

    strcpy(word, master_list[random_num]);

    return true;
}

bool display(char scrambled_word[], char normal_word[]) {
    int random_num = (rand() % (strlen(normal_word) - 1) + 1);
    char dash_string[strlen(normal_word)*2];
    int dash_index;
    char dash = '_';
    cout << "\n" <<"LET THE GAME BEGIN" << "\n\n" << endl;
    cout << " The word you're trying to guess scrambled is: " << normal_word << "\n\n" << endl;

    for (int i = 0; i < (strlen(normal_word)*2); i+=2) { 
        dash_string[i] = dash;
        dash_string[i+1] = ' ';
    }
    if (!random_num % 2) {
        // uneven number
        dash_index = random_num + 1;
    } else {
        // even number
        dash_index = (random_num*2);
    }

    dash_string[dash_index] = normal_word[random_num];
    
    cout << dash_string << "\n\n" << endl;

    return false;
    
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
    char random_word[30];
    char hello[20];

    while(!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly select a word from master_list
    random_function(100, random_word, master_list);
    cout << random_word << endl;

    // scramble the word
    //fischer algorithm thingy(random_word);
    char scrambled[20] = "scrambled";

    // show the scrambled word
    display(scrambled, random_word);

    // user can guess the word
    //play();

    // ask user if they want to continue
    return 0;
}