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

    return random_num;
}*/

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
    char* pnr = new char[LENOFWORD];
    char* word = new char[200];
    bool checker = false;

    while (!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly select a word from master_list
    //random_num = random_number(100);

    int random = rand() % 101;

    strcpy(random_word, master_list[random]);
    cout << random_word << endl;

    strcpy(pnr, random_word);

    cout << pnr << endl;
    cout << sizeof(pnr) << endl;
    cout << strlen(pnr) << endl;
    randomize(pnr);
    cout << pnr << endl;

    char *word2 = new char[strlen(random_word)];
    strcpy(word2, random_word);
    while (checker != true) {
        cout << pnr << endl;
        cout << "Pleas enter a guess word: ";
        cin >> word;
        if (cmp(word, word2)){
            checker = true;
            cout << "Well Done, you have solved the crisis!!!!";
        }
    }
    

    // scramble the word
    //word_scrambler(random_word);

    // show the scrambled word
    //display_word(random_word);

    // user can guess the word
    //play();

    // ask user if they want to continue
    return 0;


}