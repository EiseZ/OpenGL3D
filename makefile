all:
	gcc -std=c17 -o bin/main src/*.c -Iinclude -Wall -Wextra -Llib -lglfw3dll -lcimgui
	bin/main.exe
