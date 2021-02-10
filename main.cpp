#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>


using namespace std; // only for 

int LENOFWORD = 20;
int LENOFFILE = 100;

/*int random_number(int max_num) {
    int random_num;

    srand(time(0));
    random_num = (rand() % max_num) + 1;

    strcpy(word, master_list[random_num]);

    return true;
}
bool random_function(int max_num, char word[], char master_list[][30]) {

}

*/

bool display(char *scrambled_word, char *normal_word) {
    int random_num = (rand() % (strlen(normal_word) - 1) + 1);

    char dash_string[strlen(normal_word)*2];
    int dash_index;
    char dash = '_';
    cout << "\n" <<"LET THE GAME BEGIN" << "\n\n" << endl;
    cout << " The word you're trying to guess scrambled is: " << scrambled_word << "\n\n" << endl;

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
    
    return random_num;
}

void swap(char *arr, int i, int j) {

    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void randomize(char *pnr) {
    
    srand(time(NULL));

    for (int i = strlen(pnr) - 1; i > 0; i--) {
        

        int j = rand() % (i + 1);

        swap(pnr, i, j);
    }
}

bool cmp(char* word, char* random_word) {
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

int main() {

    srand(time(NULL));
    ofstream fout;
    ifstream fin;
    int x;
    char sum[10];

    // open a file
    fin.open("100_words.fic", ios::binary | ios::in);

    char the_string[LENOFWORD];
    int lenOfString;
    int counter = 0;
    char master_list[LENOFFILE][LENOFWORD];
    int random_num;
    char random_word[LENOFWORD];
    char* pnr = new char[LENOFWORD]; // pointer to random_word
    char* word = new char[200]; // pointer to input word
    bool checker = false;
    char letter; // input letter to keep going

    while (!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly select a word from master_list
    int random = rand() % 101;
    strcpy(random_word, master_list[random]);
    //cout << random_word << endl;
    
    strcpy(pnr, random_word);

    //cout << pnr << endl;
    //cout << sizeof(pnr) << endl;
    //cout << strlen(pnr) << endl;

    randomize(pnr); // scrambling the random_word
    cout << pnr << endl;

    char *word2 = new char[strlen(random_word)]; // not scrambled random_word
    strcpy(word2, random_word);
    display(pnr, word2);


    /*
    while (checker != true) {
        cout << pnr << endl;
        cout << "Please enter a guess word: ";
        cin >> word;
        if (cmp(word, word2)){
            cout << "Continue?(y/n)";
            cin >> letter;
            cout << "Well Done, you have solved the crisis!!!!" << endl;
            if (letter == 'y') {
                randomize(pnr);
                continue;
            }
            if(letter == 'n'){
                checker = true;
            }
        }
    }
    */
    
    

    // scramble the word
    //fischer algorithm thingy(random_word);

    // show the scrambled word

    // user can guess the word
    //play();

    // ask user if they want to continue
    return 0;
}