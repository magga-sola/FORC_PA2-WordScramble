#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "helper.h"
using namespace std;
using namespace std::chrono;

void WordJumble::set_checker () {
    checker = false;
}
void WordJumble::set_iteration_counter(int i) {
    iteration_counter = i;
}

void WordJumble::initialize () {
    points = 10;
    pnr = new char[20];
    word = new char[200]; // pointer to input word
    checker = false;
    overall_hint_counter = 0;
}
void WordJumble::set_random_word() {
    //cout << "Line 1" << endl;
    hint_counter = 0;
    //cout << "Line 2" << endl;
    get_random_word();
    //cout << "Line 3" << endl;
    create_dash(lenOfRandom);
    //cout << "Line 4" << endl;
}

void WordJumble::guess_word() {
    char hint_checker;
    bool quit = false;
    hintsleft = 0;
    // returns when a person gets it or 
    while (quit == false) {
        cout << "\n" << " The word you're trying to guess scrambled is: " << pnr << "\n\n" << endl;
        cout << "Please enter a guess word: ";
        cin >> word;
        if (cmp(word, word2)){
            delete[] word2;
            delete[] pnr;
            delete[] word;
            delete[] random_word;
            cout << "Well Done, you have solved the crisis!!!!" << endl;
            quit = true;
        } else {
            if (points == 0) {
                cout << "You guessed " << iteration_counter << " words correctly!" << endl;
                return;
            }
            cout << "Would you like a hint? (y) ";
            cin >> hint_checker;
            if (hint_checker == 'y') {
                hint();
                hint_counter++;
                overall_hint_counter++;
                cout << "You have " << hintsleft << " hints left" << endl;
            }
        }
    }
}
            
void WordJumble::create_dash (int len) {
    char dash = '_';
    char dashes[len];
    for (int i = 0; i < len; i++) {
        hint_array[i] = dash;
    }
}

void WordJumble::get_random_word() {
    ifstream fin;
    //cout << "Line 1" << endl;
    char the_string[20];
    //cout << "Line 2" << endl;
    int counter = 0;

    // read the file
    fin.open("100_words.fic", ios::binary | ios::in);
    //cout << "Line 3" << endl;
    while (!fin.eof()) {
        fin >> the_string;
        strcpy(this->master_list[counter], the_string);
        counter++;
    }
    //cout << "Hello world" << endl;
    fin.close();
    //cout << "Line 4" << endl;

    // randomly choose from it
    int random = rand() % 101;
    strcpy(random_word, master_list[random]);
    //cout << "Line 5" << endl;
    strcpy(pnr, random_word);
    //cout << "Line 6" << endl;
    lenOfRandom = strlen(pnr);
    randomize(pnr); // scrambling the random_word
    //cout << "Line 6" << endl;
    word2 = new char[strlen(random_word)]; // not scrambled random_word
    //cout << "Line 7" << endl;
    strcpy(word2, random_word);
    //cout << "Line 8" << endl;

}

void WordJumble::randomize(char *pnr) {
    srand(time(NULL));

    for (int i = strlen(pnr) - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(pnr, i, j);
    }
}

void WordJumble::swap(char *arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool WordJumble::cmp(char *firt_string, char *second_string) {
    if (strlen(word) != strlen(random_word)) {
        return false;
    }
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] != random_word[i]) {
            return false;
        }
    }
    return true;
}

void WordJumble::hint() {
    //cout << "\033[2J\033[1;1H"; 
    //cout << "\n" << endl;
    // add a random number
    if (hint_counter < lenOfRandom) {
        int random_num = (rand() % lenOfRandom);
        while (hint_array[random_num] != '_') {
            // try again
            random_num = (rand() % lenOfRandom);
        }
        hint_array[random_num] = random_word[random_num];
    } 
    for (int i = 0; i < lenOfRandom; i++) {
        cout << hint_array[i] << " ";
    }
}

void WordJumble::calculateScore(auto start, auto stop) {
    auto duration = duration_cast<seconds>(stop - start).count();

    points = ((duration * 10)/ overall_hint_counter) + points - overall_hint_counter;
    
}

int main() {
    WordJumble scrambleWord;
    bool quit = false;
    char letter;
    srand(time(NULL));
    scrambleWord.initialize();
    int iter_count = 0;
    char *random_word = new char [20];
    //cout << "Hello 1" << endl;
    auto start = steady_clock::now();
    while (scrambleWord.checker == false) {
        //cout << "Hello 2" << endl;
        iter_count++;
        scrambleWord.set_iteration_counter(iter_count);
        //cout << "Hello 3" << endl;
        scrambleWord.set_random_word();
        //cout << "Hello 4" << endl;
        random_word = scrambleWord.pnr;
        // plays the game
        scrambleWord.guess_word();
        //cout << "Hello 5" << endl;
        if (iter_count == 7) {
            auto stop = steady_clock::now();
            scrambleWord.calculateScore(start, stop);
            cout << "You finished with " << scrambleWord.points << " points left!" << endl;
            cout << "And it took you" << scrambleWord.duration << " seconds" << endl;
            break; 

        }
        cout << "Continue? (y) ";
        cin >> letter;
        cout << letter << endl;
        if (letter != 'y') { 
            break; 
        }
    }
    return 0;
}
                               