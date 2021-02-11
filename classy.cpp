#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class WordJumble {
    public:
        char hint_array[20];
        char master_list[100][20];
        char random_word[20];
        int points;
        int iteration_counter;
        char *pnr;
        char* word; // pointer to input word
        char* word2;
        int lenOfRandom;
        bool checker;
        int overall_hint_counter;
        int hint_counter;
        // methods
        void create_dash(int);
        void initialize();
        void randomize(char *);
        bool cmp(char *, char *);
        void hint();
        void get_random_word();
        void guess_word();
        void swap(char *, int, int);
        void set_random_word();
        void set_checker();
        void set_iteration_counter(int);
};
void WordJumble::set_checker () {
    checker = false;
}
void WordJumble::set_iteration_counter(int i ) {
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
    hint_counter = 0;
    get_random_word();
    create_dash(lenOfRandom);
}

void WordJumble::guess_word() {
    char hint_checker;
    bool quit = false;
    // returns when a person gets it or 
    while (quit == false) {
        cout << "\n" << " The word you're trying to guess scrambled is: " << pnr << "\n\n" << endl;
        cout << "Please enter a guess word: ";
        cin >> word;
        if (cmp(word, word2)){
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
                points--;
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
    char the_string[20];
    int counter;

    // read the file
    fin.open("100_words.fic", ios::binary | ios::in);

    while (!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly choose from it
    int random = rand() % 101;
    strcpy(random_word, master_list[random]);
    strcpy(pnr, random_word);

    lenOfRandom = strlen(pnr);
    randomize(pnr); // scrambling the random_word

    word2 = new char[strlen(random_word)]; // not scrambled random_word
    strcpy(word2, random_word);

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
    cout << "\033[2J\033[1;1H"; 
    cout << "\n" << endl;
    // add a random number
    if (hint_counter < lenOfRandom) {
        int random_num = (rand() % lenOfRandom);
        while (hint_array[random_num] != '_') {
            // try again
            random_num = (rand() % lenOfRandom);
        }
        hint_array[random_num] = random_word[random_num];
    } 
    cout << "hint counter:"<< hint_counter << " and len: " << lenOfRandom  << "and points" << points << endl;
    for (int i = 0; i < lenOfRandom; i++) {
        cout << hint_array[i] << " ";
    }
    cout << endl;
}

int main() {
    WordJumble hello;
    bool quit = false;
    char letter;
    srand(time(NULL));
    hello.initialize();
    int iter_count;
    char *random_word = new char [20];

    while (hello.checker == false) {
        iter_count++;
        hello.set_iteration_counter(iter_count);
        hello.set_random_word();
        random_word = hello.pnr;
        // plays the game
        hello.guess_word();

        if (hello.iteration_counter == 7) {
            cout << "You finished with " << hello.points << " points left!" << endl;
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