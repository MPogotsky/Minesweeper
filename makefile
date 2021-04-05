
CC = g++ -Wall -Werror -O3
SRC_BOARD = ./MinesweeperBoard/MinesweeperBoard.cpp
SRC_FIELD = ./Field/Field.cpp
BIN_FOLDER = ./bin

all:
	${CC} ${SRC_BOARD} ${SRC_FIELD} main.cpp -o ${BIN_FOLDER}/game
