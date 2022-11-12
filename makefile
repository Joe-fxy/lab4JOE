main:my_main.o getin.o getout.o getres.o
	g++ -o main my_main.o getin.o getout.o getres.o

getin.o:getin.cpp getin.h
	g++ -c getin.cpp
getout.o:getout.cpp getout.h
	g++ -c getout.cpp
getres.o:getres.cpp getres.h
	g++ -c getres.cpp
my_main.o:my_main.cpp getin.h getout.h getres.h
	g++ -c my_main.cpp

clean:
	rm main my_main.o getin.o getout.o getres.o


