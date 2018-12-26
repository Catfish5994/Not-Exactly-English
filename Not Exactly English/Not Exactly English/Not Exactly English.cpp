// Not Exactly English.cpp : Defines the entry point for the console application.
// This program was created for no other purpose then to entertain me at 3:00 am.
// Converts an inputted string of text to two different alternate spellings.

#include <iostream>
#include <string>
using namespace std;

string apply_rotation(string input);
char rotate_vowel(char original_vowel, int rotor_position);
bool is_vowel(char test_char);

string owo(string input);
char owo_char(char input_char);
char owo_char_first_letter(char input_char);

int main()
{
	cout << "--------Not Exactly English--------" << endl;
	cout << "enter \"exit\" to exit the program" << endl << endl;
	while (true)
	{
		string temp;

		//Get the users input.
		cout << "Input: ";
		getline(cin, temp);

		//If the user typed exit then exit the program.
		if (temp == "exit")
		{
			exit(0);
		}

		cout << endl << endl;

		//Print the rotated test to the console.
		cout << "Roto-speak:" << endl;
		cout << apply_rotation(temp) << endl << endl;

		//Apply "OwO UwU" and print.
		cout << "OwO:" << endl;
		cout << owo(temp) << endl << endl;
	}


	return 0;
}

//Applies the rotation to a string. The rotation is increased after the end of every word.
//Will not modify a vowel if it is the first letter in a word.
string apply_rotation(string input)
{
	int position = 0;
	int rotor_position = 0;
	bool first_letter = false;

	while (position < input.size())
	{
		//Check to see if position is at the beginning of a word. 
		//If so, skip changing the current letter.
		if (first_letter)
		{
			first_letter = false;
			position++;
			continue;
		}

		//Check if the next state of position is the beginning off a new word. 
		//If so, set the appropriate flag for the next loop.
		if ((input.at(position) == '\t') || (input.at(position) == '\n') || (input.at(position) == ' '))
		{
			rotor_position = (rotor_position + 1) % 5;
			first_letter = true;
		}

		//If position is at a vowel, rotate the vowel.
		if (is_vowel(input.at(position)))
		{

			input.at(position) = rotate_vowel(input.at(position), rotor_position);
		}

		//Move position to the next character in the string.
		position++;
	}

	return input;
}

//Rotate the inputed vowel the desired number of times.
char rotate_vowel(char original_vowel, int rotor_position)
{
	while (rotor_position > 0)
	{
		switch (original_vowel)
		{
		case 'a': original_vowel = 'e'; break;
		case 'e': original_vowel = 'i'; break;
		case 'i': original_vowel = 'o'; break;
		case 'o': original_vowel = 'u'; break;
		case 'u': original_vowel = 'a'; break;
		}

		rotor_position--;
	}

	return original_vowel;
}

//Returns true if the given char is a vowel.
//'y' is not a vowel, fight me.
bool is_vowel(char test_char)
{
	switch (test_char)
	{
	case 'a': return true; break;
	case 'e': return true; break;
	case 'i': return true; break;
	case 'o': return true; break;
	case 'u': return true; break;
	default: return false;
	}

	return false;
}

//OwO-fys a string. Converts most vowels and some character to open and rounded vowels.
string owo(string input)
{
	bool first_letter_in_word = true;
	for (int i = 0; i < input.size(); i++)
	{
		if (first_letter_in_word)
		{
			input.at(i) = owo_char_first_letter(input.at(i));
		}
		else
		{
			input.at(i) = owo_char(input.at(i));
		}

		first_letter_in_word = false;

		if ((input.at(i) == '\t') || (input.at(i) == '\n') || (input.at(i) == ' '))
		{
			first_letter_in_word = true;
		}
	}

	return input;
}

//Replay a character with its OwO equivalent.
char owo_char(char input_char)
{
	switch (input_char)
	{
	case 'r': return 'l'; break;
	case 'l': return 'w'; break;
	case 'o': return 'w'; break;
	case 'u': return 'w'; break;
	case 's': return 'z'; break;
	default: return input_char;
	}
}

//If a letter is at the beginning of a word then OwO-fys it requires a different set of rules.
char owo_char_first_letter(char input_char)
{
	switch (input_char)
	{
	case 'r': return 'w'; break;
	default: return input_char;
	}
}