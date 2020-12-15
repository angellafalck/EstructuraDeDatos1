#include <iostream>
#include "rlutil.h"

#define WIDTH 30
#define HEIGHT 30

using namespace std; 

//Variables snake
int xpos=0;
int ypos=0;
int direction=0;    //0=up, 1=left, 2=down, 3= right

//Board
const int size = WIDTH* HEIGHT;
int map[size]; //40x40=1600
int food = 3;
bool running;

//Falta Destructor 
void printMap();
char printChar(int num);
void printFood();
void initialize();
void updatesDirection();
void movement();
void move(int x, int y);
void start();

//Temporales
//void print(); //Revisar parametros de pantalla
// void prueba(); //Este solo era para ver si funcionaba el movimiento

void start()
{
 
    food=3;
    initialize();
    running = true;
    while (running) {
        if (kbhit()) 
            movement();
        
        updatesDirection();
        rlutil::cls();
        printMap();
        
        if(food>=3 && food <=6)
        {
            rlutil::msleep(400);
        }else if(food>=7 && food <=10)
        {
            rlutil::msleep(300);
        }else if(food>10)
        {
            rlutil::msleep(200);
        }
       
        
    }

    cout << "\n¡G A M E  O V E R!" << endl << "\nFinal Score: " << food<<endl;
    cin.ignore();
}

void printMap()
{
    rlutil::setColor(rlutil::LIGHTRED);
    cout<<"Buttons: w=up, s=down, a=right, d=left\n"<<endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<< "   S  N  A  K  E   G  A  M  E"<< endl;
    cout <<"+-----------------------------+"<< endl;

    for (int x = 0; x < WIDTH; x++) 
    {
        for (int y = 0; y < HEIGHT; y++) {
           cout << printChar(map[x+y*WIDTH]);
        }
        cout << endl;
    }
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout <<"+-----------------------------+"<< endl;
    
}


char printChar(int num)
{
    if(num>0)
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        return 'o';
        
    }else if(num==-1)
    {
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        return '|';
    }else if(num==-2)
    {
        rlutil::setColor(rlutil::LIGHTRED);
        return '@';
    }

    return ' ';
    

}

void printFood() {
    int x = 0;
    int y = 0;
    do {

        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2) + 1;

    } while (map[x + y * WIDTH] != 0);

    map[x + y * WIDTH] = -2;
}

void initialize()
{
     
    //Pone la serpiente enmedio
    xpos = 10;
    ypos = 10;

    // Paredes de abajo y arriba
    for (int x = 0; x < WIDTH; ++x) {
        map[x] = -1;
        map[x + (HEIGHT - 1) * WIDTH] = -1;
    }

    // Paredes de los lados
    for (int y = 0; y < HEIGHT; y++) {
        map[y * WIDTH] = -1;
        map[(WIDTH - 1) + y * WIDTH] = -1;
    }

    printFood();
    
}

void movement() 
{
    /*
    w= up
    s= down
    a=right
    d=left
    */

   if(kbhit()){
         switch (getch()) {
    case 'w':
        if (direction != 2)
        direction = 0;
        break;
    case 'd':
        if (direction != 3)
        direction = 1;
        break;
    case 's':
        if (direction != 4)
        direction = 2;
        break;
    case 'a':
        if (direction != 5)
        direction = 3;
        break;
    }
}
  
}

void updatesDirection() {

switch (direction) {
    case 0: 
        move(-1, 0);
    break;

    case 1: 
        move(0, 1);
    break;

    case 2: 
        move(1, 0);
    break;

    case 3: 
        move(0, -1);
    break;
    }

    for (int i = 0; i < size; i++) {
        if (map[i] > 0) map[i]--;
    }
    
}

void move(int x, int y)
{
    int newx = xpos + x;
    int newy = ypos + y;

     if (map[newx + newy * WIDTH] == -2) {
        food++;

        printFood();
    }

    else if (map[newx + newy * WIDTH] != 0) {
        running = false;
    }

    xpos = newx;
    ypos = newy;
    map[xpos + ypos * WIDTH] = food + 1;
}


/*
//Funciones de prueba
void prueba()
{
    if(kbhit()){
       
     switch(rlutil::getkey())
    {
        case rlutil::KEY_UP:
            std::cout<<"up";
            break;
        case rlutil::KEY_DOWN:
            std::cout<<"d";
            break;
        case rlutil::KEY_RIGHT:
            std::cout<<"r";
            break;

        case rlutil::KEY_LEFT:
            std::cout<<"l";
            break;

    }
    }
}

void print()
{
    rlutil::locate(0,0);
    std::cout<<"h";
    rlutil::locate(0,88);
    std::cout<<"b";
    rlutil::locate(25,0);
    std::cout<<"h";
    rlutil::locate(25,87);
    std::cout<<"a";
    rlutil::locate(3,18);


}


void printSnake()
{
    rlutil::locate(x,y);
    std::cout<<" ";
    
    
    rlutil::msleep(10);
    rlutil::locate(x,y);
    rlutil::setChar('*');
}
*/

