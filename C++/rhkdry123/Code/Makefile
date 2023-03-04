all: main.o Entry.o File.o Directory.o
	g++ -o skku_sh main.o Entry.o File.o Directory.o

main.o: testing.cc Entry.h Directory.h File.h
	g++ -c main.cc

Entry.o: Entry.cc Entry.h
	g++ -c Entry.cc

File.o: File.cc File.h
	g++ -c File.cc

Directory.o: Directory.cc Directory.h
	g++ -c Directory.cc

test:
	./skku_sh

clean:
	rm -f *.o skku_sh

