CCFLAGS = -std=c++20
CCX = g++.exe 
#Here i put g++.exe because i use the ubuntu sub system for windows and i have linked the 
#mingw i use on windows so i don't need to install gcc another time. 
#You'll probably need to edit this to make it just g++

.PHONY: debug folder clean
debug: folder
	$(CCX)  src/main.cpp src/file.cpp -o bin/morse $(CCFLAGS)
folder:
	mkdir -p bin/

clean:
	rm -f bin/*.o
	rm -f bin/*.exe
	rm -f bin/*.out
