#include <iostream>
#include <algorithm>
#include "is_palindrome.h"


using namespace std;

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
    bool done;

    cout << "Welcome to \"Palendrome Finder\" v 11.06" << endl;
    do {
        string input = get_phrase_from_user();
        print_output(is_palendrome(( input )));
        done = check_is_user_done();
    } while( !done );
    cout << "Goodbye";
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

bool check_is_user_done() {
    string input;
    cout << "Do you have another palindrome to test? [(Y)es/(N)o]: " << endl;
    cin >> input;
    return !input.empty() && tolower(input[0]) != 'y';
}

void print_output(bool is_palindrome) {
    cout << "That is " << ( is_palindrome ? "" : "not " ) << "a palendrome." << endl;
}

string get_phrase_from_user() {
    bool valid_phrase;
    string input;
    do {
        cout << "Please enter a phrase to evaluate:" << endl;
        getline(cin, input);
        valid_phrase = validate_alnum(input);
        if( !valid_phrase )
            cout << "Invalid entry: \"" << input << "\" has no alphanumeric characters to evaluate." << endl;
    } while( !valid_phrase );
    cout << "You entered \"" << input << "\"" << endl;
    return input;
}

bool validate_alnum(const string &input) {
    return std::any_of(input.begin(), input.end(), ::isalnum);
    // This would also work:
    // return std::any_of(input.begin(), input.end(), [](const char &c) { return isalnum(c);});
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

    for( int i = (int)rPhrase.length() - 1; i >= 0; i-- ) {
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


