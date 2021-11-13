//
// Created by Justin Gries on 11/12/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_06_IS_PALINDROME_H
#define CHAFFEY2021F_CS2G1_11_06_IS_PALINDROME_H

static const char EMPTY = ' ';

/**
 * Prompts the user for a phrase to be evaluated
 * Validates input to ensure that something with alphanumeric content is returned; re-prompts until valid input is
 * received
 * @return validated input string
 */
std::string get_phrase_from_user();

/**
 * Prints out the results of the palindrome test for the user
 * @param is_palindrome boolean indicating if there is a palindrome or not
 */
void print_output(bool is_palindrome);

/**
 * Prompts the user to see if they are done
 * @return true if the user enters something that starts with a "y/Y", false if not;
 */
bool check_is_user_done();

/**
 * Method to determine if a given phrase, with non-characters removed and disregarding capitalization, is a palendrome.
 * @param phrase The phrase to be evaluated. This reference variable will be destroyed in the process
 * @return true if the phrase is a palendrome, false if it is not
 */
bool is_palendrome(std::string phrase);

/**
 * Splits a phrase that is provided into a front and rear character, and a central std::string between them
 * @param rPhrase Original phrase. Will be altered by this function to provide the central std::string back to the calling
 * function
 * @param rFront reference that will contain the first character of the supplied phrase
 * @param rBack reference that will contain the last character of the supplied phrase
 */
void split_string(std::string &rPhrase, char &rFront, char &rBack);

/**
 * Checks to make sure that there are alphanumeric characters in the input.
 * @param input characters to evaluate
 * @return true if there are alphanumeric characters, false if there are not
 */
bool validate_alnum(const std::string &input);

#endif //CHAFFEY2021F_CS2G1_11_06_IS_PALINDROME_H
