CXX = g++

PROJ = snake
OBJS = main.o model.o view.o controller.o

all: $(PROJ)

$(PROJ):$(OBJS)
	$(CXX) $(OBJS) -o $(PROJ)

depend:
	$(CXX) -MM $(OBJS:.o=.cpp) > .depends

clean:
	rm $(OBJS) $(PROJ)

-include .depends

