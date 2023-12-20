main: main.c main.h \
	  pi/pi.c pi/pi.h \
	  matrix/matrix.c matrix/matrix.h \
	  strassen/strassen.c strassen/strassen.h \
	  matrix_multiplication/matrix_multiplication_simple.c matrix_multiplication/matrix_multiplication_intrinsics.c matrix_multiplication/matrix_multiplication.h
	gcc -fopenmp -mavx -mfma -o main main.c \
						 pi/pi.c \
						 matrix/matrix.c \
						 strassen/strassen.c \
						 matrix_multiplication/matrix_multiplication_simple.c \
						 matrix_multiplication/matrix_multiplication_intrinsics.c
