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



int make_dash_index(int random_num) {
    int dash_index;
    if (!random_num % 2) {
        // uneven number
        dash_index = random_num + 1;
    } else {
        // even number
        dash_index = (random_num*2);
    }
    return dash_index;
}


char* create_dash(int len) {
    char dash = '_';
    char word[len];
    for (int i=0; i < len; i++) {
        word[i] = dash;
    }
    return word;
}
/*
void modify_dash(char *normal_word, char *dash_string, int *hint_index) {
    for (int i=0; i < strlen(dash_string); i++) {
        if (hint_index[i] != '_') {
            int index = hint_index[i];
            dash_string[index] = normal_word[index];
        }
    }
    return;
}
*/

void print_dash(char *dash_string) {
    for (int i=0; i < strlen(dash_string); i++) {
        cout << dash_string[i] << " ";
    }
}

char* hint(char* dash_string, char *scrambled_word, char *normal_word) {
    int random_num = (rand() % (strlen(normal_word))); // in order to choose a random index for revealed letter
    int lenOfString = strlen(normal_word);
    dash_string = create_dash(lenOfString);
    
    //cout << "\033[2J\033[1;1H"; // clears the terminal window
    print_dash(dash_string);

    while (!(dash_string[random_num] == '_')) {
        random_num = (rand() % (strlen(normal_word) - 1) + 1); 
    }

    dash_string[random_num] = normal_word[random_num];
    cout << normal_word << endl;
    cout << "here is the dash index: " << dash_string[random_num] << " and the letter: " << normal_word[random_num] << endl;

    return dash_string;
}
/*
bool display(char *scrambled_word, char *normal_word, char hint_index[], int counter) {
    int random_num = (rand() % (strlen(normal_word) - 1) + 1); // in order to choose a random index for revealed letter
    char dash_string[strlen(normal_word)+1]; // in order to account for empty spaces in between

    for (int i = 0; i < (strlen(normal_word)+1); i++) { 
        dash_string[i] = dash;
    }

    cout << "hint_index strlen    " << strlen(hint_index) << endl;
    cout << "word len      " << strlen(normal_word) << endl;
    cout << "hint index list " << hint_index << endl;

    for (int i =0; i < strlen(hint_index); i++) {
        if (hint_index[i]) {
            int index_num = hint_index[i];

            // make index into dash index
            int dash_index2 = make_dash(index_num);
            dash_string[dash_index2] = normal_word[index_num];
        }
    }
    // while loop so that random num isn't in the hint_index array

    dash_string[random_num] = normal_word[random_num]; // random letter thingy

    //
    char char_of_num = (char)random_num;
    //

    //cout << "\033[2J\033[1;1H"; // clears the terminal window
    for (int i=0; i < strlen(normal_word); i++) {
        cout << dash_string[i] << ' ';
    }
    cout << endl;
    counter++;
    return true; 
}
*/
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
    char *dash_string = new char[lenOfRandom];
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
                char_array = hint(dash_string, pnr, word2);
            }
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
    
    
    

    // scramble the word
    //fischer algorithm thingy(random_word);

    // show the scrambled word

    // user can guess the word
    //play();

    // ask user if they want to continue
    return 0;
}
*/