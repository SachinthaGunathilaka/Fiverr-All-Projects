a1: main.o Student.o Date.o Library.o Reservation.o Room.o
	g++ -o a1 main.o Student.o Date.o Library.o Reservation.o Room.o

main.o: main.cc Library.h Date.h a1-global.cc
	g++ -c main.cc

Student.o: Student.cc Student.h
	g++ -c Student.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Library.o: Library.cc Library.h Reservation.h Student.h Room.h
	g++ -c Library.cc

Reservation.o: Reservation.cc Reservation.h Student.h Room.h Date.h
	g++ -c Reservation.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

clean:
	rm -f *.o a1

