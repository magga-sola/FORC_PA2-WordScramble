#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>


using namespace std; // only for 

int LENOFWORD = 20;
int LENOFFILE = 100;



void create_dash(int len, char word[] ){
    char dash = '_';
    for (int i=0; i < len; i++) {
        word[i] = dash;
    }
    char *p = new char[len];
    p = word;
    return;
}

void print_dash(char *dash_string) {
    int len = strlen(dash_string);

    for (int i=0; i < len; i++) {
        cout << dash_string[i] << " ";
    }
    return;
}

char *hint(char* dash_string2, char *scrambled_word, char *normal_word) {
    int random_num = (rand() % (strlen(normal_word))); // in order to choose a random index for revealed letter
    int lenOfString = strlen(normal_word);

    // checking if pointer to dash_word exists
    if (dash_string2 == NULL) {
        cout << "hello" << endl;
        dash_string2 = new char[lenOfString];
        char dash_word[lenOfString];
        create_dash(lenOfString, dash_word);
        dash_string2 = dash_word;
        dash_string2[random_num] = normal_word[random_num];
        print_dash(dash_string2);
        return dash_string2;

    }  else {
        cout << "I'm in the else!" << dash_string2 << endl;
        print_dash(dash_string2);
        while (dash_string2[random_num] != '_') {
            random_num = (rand() % (lenOfString));
        }
        dash_string2[random_num] = normal_word[random_num];

        print_dash(dash_string2);

    }  
    cout << "I'm the final pointer" << dash_string2 << endl;
    return dash_string2;
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

    char master_list[LENOFFILE][LENOFWORD];
    char random_word[LENOFWORD];
    int iteration_counter;
    int points = 10;
    char *char_array = NULL;
    char letter;
    bool checker = false;
    char *pnr = new char[LENOFWORD];
    char* word = new char[200]; // pointer to input word
    int counter;
    char the_string[LENOFWORD];
    int len;
    bool has_entered = false;

    fin.open("100_words.fic", ios::binary | ios::in);

    while (!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    int random = rand() % LENOFFILE + 1;
    strcpy(random_word, master_list[random]);

    strcpy(pnr, random_word);
    int lenOfRandom = strlen(pnr);
    randomize(pnr); // scrambling the random_word

    char *word2 = new char[strlen(random_word)]; // not scrambled random_word
    strcpy(word2, random_word);
    
    while (checker != true) {
        //cout << "\033[2J\033[1;1H"; // clears the terminal window

        cout << "\n" << " The word you're trying to guess scrambled is: " << pnr << "\n\n" << endl;
        cout << "Please enter a guess word: ";
        cin >> word;
        if (cmp(word, word2)){
            cout << "Well Done, you have solved the crisis!!!!" << endl;
            
            if (iteration_counter == 7) {
                cout << "You finished with " << points << " points" << endl;
                break;
            } 
            if (points == 0) {
                cout << "You lost at attempt: " << iteration_counter << endl;
                break;
            }
            
            cout << "Continue? (y)";
            cin >> letter;
            if (letter == 'y') {
                iteration_counter++;
                //randomize(pnr);
                continue;
            } else { break; }
            
        } else {
            cout << "Would you like a hint? (y/n)";
            cin >> letter;
            if (letter == 'y') {
                int len = strlen(pnr);
                int random_num2 = (rand() % (LENOFWORD)); // in order to choose a random index for revealed letter

                // checking if pointer to dash_word exists
                if (has_entered == false) {
                    has_entered = true;
                    cout << "hello" << endl;
                    char *dash_pointer;
                    dash_pointer = new char[len];
                    char dash_word[len];
                    create_dash(len, dash_word);
                    dash_pointer = dash_word;
                    dash_pointer[random_num2] = pnr[random_num2];
                    print_dash(dash_pointer);

                }  else {
                    cout << "I'm in the else!" << dash_pointer << endl;
                    cout << "ran thing: " << dash_pointer[random_num2] << endl; 
                    print_dash(dash_pointer);
                    while (dash_pointer[random_num2] != '_') {
                        random_num2 = (rand() % (len));
                    }
                    dash_pointer[random_num2] = pnr[random_num2];
                    print_dash(dash_pointer);
                }  
                //dash_pointer = hint(dash_pointer, pnr, word2);
            }
            points--;
        }
    }
    return 0;
}

/*
int main() {

    srand(time(NULL));
    ofstream fout;
    ifstream fin;

    // open a file

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
    char mode;



    char dash = '_';

    for (int i=0; i < LENOFWORD; i++) {
        hint_index[i] = dash;
    }

    while (!fin.eof()) {
        fin >> the_string;
        strcpy(master_list[counter], the_string);
        counter++;
    }
    fin.close();

    // randomly select a word from master_list
    int random = rand() % 101;
    strcpy(random_word, master_list[random]);
    
    strcpy(pnr, random_word);
    randomize(pnr); // scrambling the random_word

    char *word2 = new char[strlen(random_word)]; // not scrambled random_word
    strcpy(word2, random_word);
    
    while (checker != true) {
        
        //cout << "\033[2J\033[1;1H"; // clears the terminal window
        cout << "\n" << " The word you're trying to guess scrambled is: " << pnr << "\n\n" << endl;
        cout << "Please enter a guess word: ";
        cin >> word;
        if (cmp(word, word2)){
            cout << "Well Done, you have solved the crisis!!!!" << endl;
            
            if (iteration_counter == 7) {
                cout << "You finished with " << points << " points" << endl;
                break;
            }
            
            cout << "Continue?(y/n)";
            cin >> letter;
            if (letter == 'y') {
                iteration_counter++;
                randomize(pnr);
                continue;
            }
            if(letter == 'n'){
                checker = true;
            }
        } else {
            cout << "Would you like a hint? (y/n)";
            cin >> letter;
            if (letter == 'y') {
                hint(pnr, word2, hint_index, hint_index_counter);
            }
        }
        
    }
    return 0;
}
*/