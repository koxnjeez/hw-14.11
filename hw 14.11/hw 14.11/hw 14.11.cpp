#include "settings.h"

int main()
{
    // task 1
    srand(time(NULL));
    int size;
    cout << "Enter size of password (not more than 100 symbols): ";
    cin >> size;
    int num = 65 + rand() % ((90 + 1) - 65);
    char* password = new char[100];
    password[0] = (char)num;
    cout << "Generated pass: " << password[0];
    for (int i = 1; i < size; i++) {
        int numorlet = rand() % 2;
        if (numorlet == 1) {
            num = 97 + rand() % ((122 + 1) - 97);
        }
        else {
            num = 48 + rand() % ((57 + 1) - 48);
        }
        password[i] = (char)num;
        cout << password[i];
    }
    cout << "\n\n";



    // task 3
    char* text = new char[200];
    cout << "Input text: ";
    gets_s(text, 200);

    char* word = new char[100];
    cout << "Input word: ";
    gets_s(word, 100);

    int count_words = 0;
    while (true) {
        char* result = strstr(text, word); // поиск слова в строке
        if (result) {
            int index = result - text;
            count_words++;
            if (text[index] != (char)35) {
                text[index] = (char)35;
            }
        }
        else {
            break;
        }
    }
    cout << "Count of \"" << word << "\" equals " << count_words << "\n\n";



    // task 5
    char* letter_text = new char[200];
    cout << "Input text: ";
    gets_s(letter_text, 200);

    int* numsofchar = new int[246];
    for (int i = 65; i < 246; i++) {
        numsofchar[i] = 0;
    }
    for (int i = 0; i < strlen(letter_text); i++) {
        if (letter_text[i] == (char)32) {
            continue;
        }
        else {
            numsofchar[(int)letter_text[i]]++;
        }
    }
    int max_num = 0;
    int ind_max;
    for (int i = 0; i < 246; i++) {
        if (numsofchar[i] > max_num) {
            max_num = numsofchar[i];
            ind_max = i;
        }
    }
    cout << "The letter with the highest count of repetitions is \"" << (char)ind_max << "\" (" << numsofchar[ind_max] << ")\n";

    Sleep(INFINITE);
}