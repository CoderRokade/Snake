#include<iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

// this are parameters by which we are printing rectangular shape 
// game border . I use const because i want them to unchange at any cost
const int height = 20, width = 30;

// now i decided to take that snake(0) is at center of 2D plane at start
// How you can do that simply snake x and y pointer 

// int sankexco = height/2;
// int snakeyco = width/2;
int x,y,fruitx,fruity,score = 0;
bool gameover;
enum direction
{
    STOP = 0, LEFT, RIGHT, UP, DOWN
};
direction dir;

void setup(){
    gameover = false;
    dir = STOP;
    x = width/2;
    y = height/2;

    fruitx = rand()% width;
    fruity = rand()% height;

    score =0;
}


// border done of rectangular shape and ponting of snake inside cage or border

void border(){

    system("cls");

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            // printing border
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                cout<<"*";
            }

            // printing snake
            else if (i == y && j == x)
            {
                cout << "0";
            }
            // printing fruit
            else if (i == fruitx && j == fruity)
            {
                cout << "F";
            }
            // printing spaces in between
            else{
                cout<<" ";
            }            
            
        }
        cout<<endl;
    }


}

void Inputkey(){
    

    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;
        case 'x':
            gameover = true;
            break;
        }

   }

}

void logic(){
       switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
        case UP:
            y--;
            break;
        case 'x':
            gameover = true;
        break;
        }

        if(x> width || x<0 || y>height || y<0){
            gameover = true;    
        }
        
        if(x == fruitx && y == fruity){
            score += 10;
            
        }
}




int main(){

    setup();

    while(!gameover) {

    border();
    Inputkey();
    logic();

    Sleep(1000);

    
   }
   return 0;
}
