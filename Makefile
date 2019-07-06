CXX = g++ -std=c++14
CXXFLAGS = -g -std=c++14 -Wall -MMD
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = monopoly
OBJECTS = ./Game/game.o ./Board/board.o ./Player/player.o ./Tile/tile.o ./Tile/property.o ./Tile/utility.o ./Tile/transportation.o ./Color/color.o ./Card/card.o ./Card/GOJFCard.o ./Card/GTJCard.o ./Card/getMoneyCard.o ./Card/loseMoneyCard.o ./Card/moveCard.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
