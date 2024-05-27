CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
BUILD_BIN = ${BUILD}/bin
INCLUDE = ./include
SRC = ./src

${BUILD}/${TARGET}: ${BUILD_BIN}/aluno.o ${BUILD_BIN}/ponto3d.o ${BUILD_BIN}/ola.o ${BUILD_BIN}/main.o
	${CC} ${CFLAGS}  ${BUILD_BIN}/aluno.o ${BUILD_BIN}/ponto3d.o ${BUILD_BIN}/ola.o ${BUILD_BIN}/main.o -o ${BUILD}/${TARGET}

${BUILD_BIN}/aluno.o: ${INCLUDE}/Persona/aluno.hpp ${SRC}/Persona/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Persona/ -c ${SRC}/Persona/aluno.cpp -o ${BUILD_BIN}/aluno.o

${BUILD_BIN}/ponto3d.o: ${INCLUDE}/Mapa/ponto3d.hpp ${SRC}/Mapa/ponto3d.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -c ${SRC}/Mapa/ponto3d.cpp -o ${BUILD_BIN}/ponto3d.o

${BUILD_BIN}/ola.o: ${INCLUDE}/Persona/ola.hpp ${SRC}/Persona/ola.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Persona/ -c ${SRC}/Persona/ola.cpp -o ${BUILD_BIN}/ola.o

${BUILD_BIN}/main.o: ${INCLUDE}/Persona/aluno.hpp ${INCLUDE}/Mapa/ponto3d.hpp  ${INCLUDE}/Persona/ola.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Persona/ -I ${INCLUDE}/Mapa/ -c ${SRC}/main.cpp -o ${BUILD_BIN}/main.o

builder:
	if not exist build mkdir build
	if not exist build\bin mkdir build\bin

run:
	${BUILD}/${TARGET}

clean:
	del build\*.exe
	del build\bin\*.o

test:
	g++ -std=c++11 -Wall -g test.cpp -o progTeste
	.\progTeste.exe

cleanTest:
	del progTeste.exe