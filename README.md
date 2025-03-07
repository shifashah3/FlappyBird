### Flappy Bird - OOP Edition  

This project is a Flappy Bird clone built using **C++** and the **SDL2 library**. It incorporates **Object-Oriented Programming (OOP) principles**, including **abstraction, inheritance, operator overloading, and runtime polymorphism**, to create an interactive game with structured and modular code.  

### Features  
- **Classic Flappy Bird mechanics** – navigate through obstacles and aim for 5 coins to win the game.  
- **Smooth graphics and animations** powered by **SDL2**.  
- **Background music and sound effects** using **SDL2_mixer**.  
- **Collision detection system** for pipes.  

### Requirements  
- **C++ Compiler** (**MinGW** recommended for Windows)  
- **SDL2 Libraries**:  
  - `SDL2`  
  - `SDL2_image`  
  - `SDL2_mixer`  

### How to Compile and Run  

#### Windows  
Open the project folder in **VSCode** (or any terminal) and run:  
```sh
g++ *.cpp -I C:\mingw_dev_lib\include -L C:\mingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -o game.exe
```
Then, execute the game:  
```sh
game.exe
```

**Note:** The provided files are configured for Windows. If using another OS, modifications may be required.
