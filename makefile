
CC = g++ -Wall -Werror -O3
SRC_BOARD = ./MinesweeperBoard/MinesweeperBoard.cpp
SRC_FIELD = ./Field/Field.cpp
SRC_VIEW = ./MSBoardTextView/MSBoardTextView.cpp
BIN_FOLDER = ./bin

all:
	${CC} ${SRC_BOARD} ${SRC_FIELD} ${SRC_VIEW} main.cpp -o ${BIN_FOLDER}/game
