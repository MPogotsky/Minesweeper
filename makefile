
CC = g++ -Wall -Werror -O3
SRC = ./MinesweeperBoard/MinesweeperBoard.cpp
BIN_FOLDER = ./bin

all:
	${CC} ${SRC} main.cpp -o ${BIN_FOLDER}/game
