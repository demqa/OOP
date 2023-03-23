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

TUIView : View

list<snake> snakes;

model.update_subscribe(view);

view {
    list<snake> subs;
    
    for (auto snake: subs) {
        update(snake);
    }
}

set_timer(timeout);

timeout -= value;

if (timeout <= 0) 
    timeout.func();
    

