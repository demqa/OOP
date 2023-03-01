# OOP course in C++

### Game: Snake

Snakes eat rabbits. 

|-----------------|
|                 |
| *  <-snake1     |
|                 |
|                 |
|   ^             |
|   ---snake2     |
|                 |
|                 |
| <-auto_snake    |
|                 |
|-----------------|

2 views: text & graphic

#### 4 files:

1. model.cpp
2. view.cpp
3. controller.cpp
4. Makefile

#### EVENT LOOP

1. time
2. keyboard

// INTO VIEW

draw mechanism
runloop

object subscribtion on key... 

setOnKey(method onkey());

snake::onKey() { /* code */ };

v = getView();
v.setonkey(snake::onKey);
