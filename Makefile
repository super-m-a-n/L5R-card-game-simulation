INC = ./include
SRC = ./src

OBJS= $(SRC)/main.o $(SRC)/DeckBuilder.o $(SRC)/Personality.o $(SRC)/Player.o $(SRC)/GameBoard.o $(SRC)/TypeConverter.o
CPPFLAGS = -g -Wall -I$(INC)
PROGRAM= game

$(PROGRAM): clean $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)
