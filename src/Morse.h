#ifndef MORSEDECODER_H
#define MORSEDECODER_H
#include "tree.h"

class Morse {
	struct MorseNode
	{
		char info;
		MorseNode* left;
		MorseNode* right;
		~MorseNode() { //destructor
			delete left;
			delete right;
		}
	};

	class Character : TreeStackable<Character> {
	private:
		char value;
		string morseValue;
	public:
		Character(char c) {
			value = std::toupper(c);
			morseValue = "";
		}
		Character(char c, string m) {
			value = c;
			morseValue = m;
		}
		char getCValue() {
			return value;
		}
		string getMorseValue() {
			return morseValue;
		}
		int compareTo(Character c) {
			if (value > c.getCValue())
				return 1;
			else if (value < c.getCValue())
				return -1;
			else
				return 0;
		}

		string toString() {
			return value + "";
		}
	};

private:
	MorseNode* root;
	AVLTree<Character> encoder;

	void add(string s, char value) {
		MorseNode* aux = root;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == DASH) {
				if(aux->right == NULL)
					aux->right = new MorseNode{};
				aux = aux->right;
			}
			else if (s[i] == DOT) {
				if(aux->left == NULL)
					aux->left = new MorseNode{};
				aux = aux->left;
			}
			else {
				cout << "ERROR";
			}
				
		}
		aux->info = value;

		encoder.add(Character(value, s));
	}

	char _morseDecode(string s) {
		if (s == "/")
			return ' ';
		MorseNode* aux = root;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == DASH)
				aux = aux->right;
			else if (s[i] == DOT)
				aux = aux->left;
		}
		return aux->info;
	}

	string _morseEncode(char c) {
		Character character = encoder.get(Character(c));
		return character.getMorseValue();
	}

public:
	const char DASH = '-';
	const char DOT = '.';
	Morse() {
		root = new MorseNode{' '};
		encoder = AVLTree<Character>();
		add(".", 'E');
		add("-", 'T');
		add("..", 'I');
		add(".-", 'A');
		add("-.", 'N');
		add("--", 'M');
		add("...", 'S');
		add("..-", 'U');
		add(".-.", 'R');
		add(".--", 'W');
		add("-..", 'D');
		add("-.-", 'K');
		add("--.", 'G');
		add("---", 'O');
		add("....", 'H');
		add("...-", 'V');
		add("..-.", 'F');
		add(".-..", 'L');
		add(".--.", 'P');
		add(".---", 'J');
		add("-...", 'B');
		add("-..-", 'X');
		add("-.-.", 'C');
		add("-.--", 'Y');
		add("--..", 'Z');
		add("--..--", ',');
		add(".-.-.-", '.');
		add("..--..", '?');
		add("--.-", 'Q');
		add("--.--", '�');
		add(".....", '5');
		add("....-", '4');
		add("...--", '3');
		add("..---", '2');
		add(".-.-.", '+');
		add(".----", '1');
		add("-....", '6');
		add("-...-", '=');
		add("-..-.", '/');
		add("--...", '7');
		add("---..", '8');
		add("----.", '9');
		add("-----", '0');
		
		encoder.add(Character(' ', "/"));
	}
	~Morse() {
		delete root;
		encoder.~AVLTree();
	}

	string morseDecode(string msg) {
		string aux = "",
			   result = "";
		for (int i = 0; i < msg.length(); i++) {
			if (msg[i] == ' ') {
				result += _morseDecode(aux);
				aux = "";
			}
			else
				aux += msg[i];
		}
		result += _morseDecode(aux);
		return result;
	}

	string morseEncode(string msg) {
		string result = "";
		for (int i = 0; i < msg.length(); i++) {
			result += _morseEncode(msg[i]);
			result += " ";
		}
		return result;
	}
};

#endif
