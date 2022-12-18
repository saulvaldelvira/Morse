CCFLAGS = -std=c++20
CCX = g++.exe

.PHONY: debug folder clean
debug: folder
	$(CCX)  src/main.cpp src/file.cpp -o bin/morse $(CCFLAGS)
folder:
	mkdir -p bin/

clean:
	rm -f bin/*.o
	rm -f bin/*.exe
	rm -f bin/*.out
