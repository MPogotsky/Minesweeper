
CC = g++ -Wall -Werror -O3
SRC_BOARD = ./MinesweeperBoard/MinesweeperBoard.cpp
SRC_FIELD = ./Field/Field.cpp
SRC_VIEW = ./MSBoardTextView/MSBoardTextView.cpp
SRC_CONTROLLER = ./MSTextController/MSTextController.cpp
BIN_FOLDER = ./bin

all:
	${CC} ${SRC_BOARD} ${SRC_FIELD} ${SRC_VIEW} ${SRC_CONTROLLER} main.cpp -o ${BIN_FOLDER}/game
