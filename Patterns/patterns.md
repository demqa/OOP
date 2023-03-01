# 1. MODEL---VIEW---CONTROLLER

///////MODEL////////
nothing about view

///////VIEW/////////

/////CONTROLLER/////

# 2. ABSTRACT FABRIQUE. SINGLETON

View:

virtual void draw() = 0; // abstract
virtual ~View() {};
draw(Snake)


||
|\
| ---------------|
|                |
TUIView          GUIView

draw();          draw();


TUIView == pty which is tty

GUIView == SFML

#### TUI

Task:
1. function get window size  // DONE
2. function put xy
3. function hline, vline
4. function clear screen     // DONE

# Lesson 3

### Task

```
int a[] = {1, 2, 3, 4, 5};
int sum = 0; // calculate sum 
```

12 different functions.

0. cycle
1. auto-iterator
2. 
3. accumulate
4. for_each with lambda
5. for_each with template

##### method 0

```
// just for cycle

for (int i = 0; i < 5; ++i) sum += a[i];
```

##### method 1

```
// auto-iterator

for (const auto& elem: a) sum += elem;
```

##### method 2

```
// for each with struct

struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};

auto s = std::for_each(a, a + 5, Sum());
```

##### method 3

```
template <typename T>
struct Sum
{
    T sum;

    Sum(const T& def): sum(def) {};

    void operator()(T &n) { sum += n; }
};

auto s = std::for_each(a, a + 5, Sum{0});
```

##### method 4

```
int s = 0;
    
auto sum = [&](const int& num){ s += num; };
std::for_each(a, a + 5, sum);
```

##### method 5

```
auto s = std::accumulate(a, a + 5, 0);
```

// kotlin

```
list a(1, 2, 3)
mutableList a(1, 2, 3);
```
























