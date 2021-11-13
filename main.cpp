#include <iostream>

using namespace std;

static const char EMPTY = ' ';

/**
 * Method to determine if a given phrase, with non-characters removed and disregarding capitalization, is a palendrome.
 * @param phrase The phrase to be evaluated. This reference variable will be destroyed in the process
 * @return true if the phrase is a palendrome, false if it is not
 */
bool is_palendrome(string phrase);

/**
 * Splits a phrase that is provided into a front and rear character, and a central string between them
 * @param rPhrase Original phrase. Will be altered by this function to provide the central string back to the calling
 * function
 * @param rFront reference that will contain the first character of the supplied phrase
 * @param rBack reference that will contain the last character of the supplied phrase
 */
void split_string(string &rPhrase, char &rFront, char &rBack);

/**
 * Course: Chaffey College 2021-Fall CS2
 * Prof: Dr. Tracy Kocher
 * Date: 12 Nov 2021
 * Project: 11.06
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt: Refine the is_palindrome function to work with arbitrary strings, by ignoring non-letter characters and
 * the distinction between upper- and lowercase letters. For example, if the input string is
   "Madam, I’m Adam!" then you’d first strip off the last character because it isn’t a letter, and recursively check
   whether the shorter string "Madam, I’m Adam" is a palindrome.
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    string phrase = "Madam, I'm Adam!!!";
    cout << "You entered \"" << phrase << "\"" << endl;
    bool is_palindrome = is_palendrome(( phrase ));
    if( is_palindrome ) {
        cout << "That is either a palendrome, or it contained no alphanumeric characters." << endl;
    } else {
        cout << "That is not a palindrome." << endl;
    }
    return 0;
}

bool is_palendrome(string phrase) {
    if( phrase.length() < 2 )
        return true;
    char front = EMPTY;
    char back = EMPTY;
    split_string(phrase, front, back);
    return ( toupper(front) == toupper(back)) && ( is_palendrome(phrase));
}

void split_string(string &rPhrase, char &rFront, char &rBack) {
    char front = EMPTY;
    char back = EMPTY;
    for( int i = 0; i < rPhrase.length(); i++ ) {
        if( isalnum(rPhrase[i])) {
            front = rPhrase[i];
            rPhrase.erase(0, i + 1);
            break;
        }
    }
    if( rPhrase.empty())
        return; // phrase had no more than 1 alphanumeric character.

    for( int i = rPhrase.length() - 1; i >= 0; i-- ) {
        if( isalnum(rPhrase[i])) {
            back = rPhrase[i];
            rPhrase.erase(i, rPhrase.length() - 1);
            break;
        }
    }
    if( back == EMPTY ) {// couldn't find a second character.
        rPhrase = "";
        return;
    }

    rFront = front;
    rBack = back;
}


