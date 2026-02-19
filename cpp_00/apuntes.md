
# C++ Module 00 — Notes Summary

## File Extensions
- `.hpp` — C++ header (declarations only). Signals "this is C++", unlike `.h` which is ambiguous
- `.cpp` — C++ source (implementations). Equivalent of `.c`
- `.tpp` — Template implementation files. Included at bottom of `.hpp`. Not needed for Module 00

## Forbidden Stuff
- `namespace <name>` — equivalent to `import lib as thing`. namespace is considered bad practice in C++
- `friend` keyword — allows body of certain functions access private data of class. Breaks encapsulation. Rarely used.
	- Valid uses of `friend`: operator overloading, tightly coupled classes
- STL containers (`vector`, `list`, `map`) and `<algorithm>` — Forbidden until Modules 08-09

## new / delete (replaces malloc/free)

- `new`
	- mallocs mem: aware of class size
	- returns correct pointer type (no void \*)
	- AND calls default constructors
- `delete`
	- calls destructor then frees memory
- `delete[]`
	- used for arrays — using `delete` on an array is undefined behavior
## Orthodox Canonical Form (Module 02+, not Module 00)
Good C++ practice,. EVERY class must contain
- Default constructor
- Copy constructor
- Copy assignment operator (`=`)
- Destructor

///
* Templates are type-safe and compiler aware

## Compilation
Need to use a different compiler for LINKING c++ code

specifically: cc vs c++
  - cc (or gcc) — compiles C and C++ code just fine, but at the linking stage it only links the C standard library (libc).                                                                    
  - c++ (or g++) — compiles the same way, but also links libstdc++ (the C++ standard library) automatically.                                                                                  

you can technically keep cc and add -lstdc++ to the linker flags, but using c++ is the standard/clean way to do it for C++ projects.      

---

## Appendix — Code Examples

### new / delete vs malloc / free

```c
// C
int *p = malloc(sizeof(int));
*p = 42;
free(p);

int *arr = malloc(sizeof(int) * 10);
free(arr);
```

```cpp
// C++
int *p = new int(42);
delete p;

int *arr = new int[10];
delete[] arr;
```

### Constructor / Destructor vs C init/destroy

```c
// C
t_player *p = malloc(sizeof(t_player));
init_player(p, "name", 100);
destroy_player(p);
free(p);
```

```cpp
// C++ (heap)
Player *p = new Player("name", 100);  // constructor automatic
delete p;                              // destructor automatic

// C++ (stack — even simpler)
Player p("name", 100);     // constructor runs
// destructor runs automatically when p goes out of scope
```

### Header / Source Split

```cpp
// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
    Player();
    void takeDamage(int amount);
private:
    int _hp;
};

#endif
```

```cpp
// Player.cpp
#include "Player.hpp"

Player::Player() {
    _hp = 100;
}

void Player::takeDamage(int amount) {
    _hp -= amount;
}
```

### Self-Contained Headers with Include Guards

```cpp
// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string _name;
public:
    std::string getName();
};

#endif
```

```cpp
// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"  // includes its own dependency

class PhoneBook {
private:
    Contact _contacts[8];
public:
    void addContact();
};

#endif
```

### Orthodox Canonical Form (Module 02+)

```cpp
class Example {
public:
    Example();                                // default constructor
    Example(const Example &other);            // copy constructor
    Example& operator=(const Example &other); // copy assignment operator
    ~Example();                               // destructor
};
```


```cpp
// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    Player();                                  // default constructor
    Player(const char *name, int hp);          // parameterized constructor
    Player(const Player &other);               // copy constructor
    Player& operator=(const Player &other);    // copy assignment operator
    ~Player();                                 // destructor

private:
    char *_name;
    int   _hp;
};

#endif

// Player.cpp
#include "Player.hpp"
#include <cstring>
#include <iostream>

// Default constructor
Player::Player() : _name(NULL), _hp(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Player::Player(const char *name, int hp) : _hp(hp) {
    _name = new char[std::strlen(name) + 1];
    std::strcpy(_name, name);
    std::cout << "Constructor called for " << _name << std::endl;
}

// Copy constructor — deep copy
Player::Player(const Player &other) : _hp(other._hp) {
    if (other._name) {
        _name = new char[std::strlen(other._name) + 1];
        std::strcpy(_name, other._name);
    } else {
        _name = NULL;
    }
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator — deep copy + handle self-assignment
Player& Player::operator=(const Player &other) {
    std::cout << "Copy assignment called" << std::endl;
    if (this != &other) {          // avoid self-assignment
        delete[] _name;            // free old memory
        _hp = other._hp;
        if (other._name) {
            _name = new char[std::strlen(other._name) + 1];
            std::strcpy(_name, other._name);
        } else {
            _name = NULL;
        }
    }
    return *this;
}

// Destructor
Player::~Player() {
    std::cout << "Destructor called for " << (_name ? _name : "unnamed") << std::endl;
    delete[] _name;
}
```

