all: dat2inc datafile

datafile: datafile.o bme_end.o
	gcc -o datafile datafile.o bme_end.o
	strip datafile

dat2inc: dat2inc.o
	gcc -o dat2inc dat2inc.o
	strip dat2inc

