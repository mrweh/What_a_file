CC = g++
LIBS = -LD:/SFML-2.4.2/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE = -ID:/SFML-2.4.2/include

main.o:
	$(CC) -o lib/main.o -c main.cpp $(INCLUDE)

circles.o:
	$(CC) -o lib/circles.o -c circles.cpp $(INCLUDE)

circles.dll: circles.o
	$(CC) -shared -o circles.dll lib/circles.o $(INCLUDE), -Wl,--out-implib,lib_dll.a, $(LIBS)

Lab03: main.o circles.dll
	$(CC) -o lab.exe lib/main.o circles.dll $(LIBS)
