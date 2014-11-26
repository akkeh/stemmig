#CC-compiler:
CC=g++
CFLAGS = -Wall

DIR=audio_proc

OBJ = diss_curve.o ${DIR}/wavio.o ${DIR}/amps.o ${DIR}/simple_proc.o ${DIR}/ztrans.o ${DIR}/dft.o

all: test

test: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}

clean:
	rm -rf *.o
	rm -f audio_proc/*.o
