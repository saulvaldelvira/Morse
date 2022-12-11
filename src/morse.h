#ifndef MORSEDECODER_H
#define MORSEDECODER_H
#include <map>
#include <string>
using std::string;
using std::map;

namespace saulv{
/// @brief Morse class. It can encode or decode from morse to readable text and viceversa.
class Morse {
	
private:
	/*Morse Node, for the tree structure.
	This class uses a Binary Tree to decode morse messages.
	*/
	typedef struct sMorseNode
	{
		char info;
		sMorseNode* left;
		sMorseNode* right;
		~sMorseNode() {
			delete left;
			delete right;
		}
	} MorseNode;
	
	MorseNode* root;

	map<char, string> encoder;

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
				//std::cout << "ERROR";
			}
				
		}
		aux->info = value;

		encoder[value] = s;
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
		c = std::toupper(c);
		if(!encoder.contains(c))
			return "?";
		return encoder[c];
	}

public:
	const char DASH = '-';
	const char DOT = '.';
	Morse() {
		root = new MorseNode{' '}; //the root does not contain anything, it is just a start point.
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
		
		//add these extra characters to the encoder, so we can recover the spaces
		encoder[' '] = "/";
		encoder['\n'] = "\n";
		encoder[';'] = ""; // TODO: Make a way to decode ';'. Add it to one of the empty nodes 
		
	}
	~Morse() {
		delete root;
	}

	string morseDecode(string msg) {
		string aux = "",
			   result = "";
		for (int i = 0; i < msg.length(); i++) {
			if (msg[i] == ' ') {
				result += _morseDecode(aux);
				aux = "";
			}else if(msg[i] == '\n'){
				result += _morseDecode(aux);
				result += "\n";
				aux = "";
			}else
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
}
#endif
