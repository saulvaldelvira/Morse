# Morse
This is a simple aplication implemented in C++.
It is a translator from morse code to normal readable text and viceversa. <br>
The interface is pretty simple: You can either encode or decode morse messages, and you can choose to do it from a file or from the terminal itself. <br>
It is silly, and not very professional. I made it purely for the sake of learning and improving my skills, so don't take it very seriously. Still I think it could be useful, at least for educational purposes.

The aplication is NOT case sensitive, so 'n' and 'N' are the same. Also, when decoding, the output will allways be uppercase.

## Example:
Encoding from the terminal<br>
![imagen](https://user-images.githubusercontent.com/84346214/206918966-b3c7e9a9-714a-4ac4-ba3a-4f04923afbf6.png)

Decoding the previous message <br>
![imagen](https://user-images.githubusercontent.com/84346214/206919032-669fb384-b689-4deb-b9fd-18e3fbec5473.png)

  NOTE: When you input through the console, it reads lines until you input an empty one.

## saulv::Morse
Apart from the executable aplication, you can download the "Morse.h" header file. <br>
It includes a class (saulv::Morse) wich you can use for whatever you want in your proyects :)

## How it works
The saulv::Morse class uses a Binary Tree to decode morse text.

![imagen](https://user-images.githubusercontent.com/84346214/206912776-2b6f7f10-bcf6-4f73-a5dc-aab5743c1db8.png)
In the image above you can see how it works. While parsing a morse string of Dots and Dashes representing a character, we move to the right with every Dash, 
and to the left with every Dot.
If i have a morse text like "\-\.\-\.", following the tree i get the character 'C'.

  NOTE: I've added a few more characters that are not in this image, like '.' and ','. <br>
  Also, '/' is a whitespace, so "\-\.\-\. / \-\.\-\." would be "C C"

## Compiling
You can run the following command in the src folder.
```
g++ file.cpp main.cpp -o ../bin/morse -std=c++20
```
NOTE: you'll need to create a bin folder in the root of this proyect for this command to work. Anyways, theres a 
build.bat file and a Makefile that does everything for you
