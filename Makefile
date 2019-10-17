M = Main
AT = AlwaysTaken
ANT = AlwaysNTaken
SB = SingleBit
DB = DoubleBit
G = Gshare
P = predictors



CFLAGS= -std=c++14 

Main: $(M)

$(M):$(M).o $(AT).o $(ANT).o $(SB).o $(DB).o $(G).o
	g++ $(M).o $(AT).o $(ANT).o $(SB).o $(DB).o $(G).o -o $(P)



$(AT).o:$(AT).cpp 
	g++ $(CFLAGS) -c $(AT).cpp -o $(AT).o

$(ANT).o:$(ANT).cpp 
	g++ $(CFLAGS) -c $(ANT).cpp -o $(ANT).o


$(SB).o:$(SB).cpp 
	g++ $(CFLAGS) -c $(SB).cpp -o $(SB).o


$(DB).o:$(DB).cpp 
	g++ $(CFLAGS) -c $(DB).cpp -o $(DB).o

$(G).o:$(G).cpp 
	g++ $(CFLAGS) -c $(G).cpp -o $(G).o


#memcheck: program2
#	valgrind --track-origins=yes --leak-check=full ./program2

clean:
	rm -rf *.o  $(M)

run: $(M)
 	#./$(P)