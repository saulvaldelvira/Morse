CCFLAGS = -std=c++20

.PHONY: debug folder clean
debug: folder
	g++.exe  src/main.cpp src/file.cpp -o bin/morse.exe $(CCFLAGS)
folder:
	mkdir -p bin/

clean:
	rm -f bin/*.o
	rm -f bin/*.exe
	rm -f bin/*.out
