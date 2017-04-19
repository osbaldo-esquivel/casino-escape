# Osbaldo Esquivel
# 10MAR2015

CXX = g++

CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS = main.cpp

HEADERS = Room.h Person.h Bathroom.h BlackJack.h Craps.h Gym.h Poker.h Slot.h SportsBar.h Vault.h Vip.h Gift.h

PROGS = finalProject

all: ${PROGS}

finalProject: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROGS}

clean:
	rm -f *.o *~
