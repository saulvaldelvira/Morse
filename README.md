# Morse
This is a simple aplication implemented in C++.
It is a translator from morse code to normal readable text and viceversa. <br>
The interface is pretty simple: You can either encode or decode morse messages, and you can choose to do it from a file or from the terminal itself. <br>
It is silly, and not very professional. I made it purely for the sake of learning and improving my skills, so don't take it very seriously. Still I think it could be useful, at least for educational purposes.

## saulv::Morse
Apart from the executable aplication, you can download the Morse.h file. It includes a class (saulv::Morse) that you 
can use for whatever you want. I dont know, maybe someone will find it useful :)

## How it works
The saulv::Morse class uses a Binary Tree to decode morse text.

![imagen](https://user-images.githubusercontent.com/84346214/206912776-2b6f7f10-bcf6-4f73-a5dc-aab5743c1db8.png)
In the image above you can see how it works. If i have a morse text like "\_\.", following the tree i get the letter N.

  NOTE: I've added a few more characters that are not in this image, like '.' and ','.

## Compiling
You can run the following command in the src folder.
```
g++ file.cpp main.cpp -o ../bin/morse -std=c++20
```
