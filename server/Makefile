server: server.o database.o
	cc -o server.exe server.o database.o
server.o: server.c
	cc -c server.c
database.o: ./src/database.c
	cc -c ./src/database.c