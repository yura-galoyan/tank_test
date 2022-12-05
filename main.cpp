#include <ncurses.h>
#include <unistd.h>


class BULLET{
    private:
        int dx = 1;
        int x = 5,y = 15;

    public:
        bool colision(){
            if(x > 58){
                return false;
            }
            else return true;
        };
        int getx(){
            return x;
        }
        void shoot(){
            mvprintw(y,x,"\b ");
            x +=dx;
            mvprintw(y,x," -");
            usleep(20000);
        };

        void erase(){
                mvprintw(y,x - 2,"      ");

        }

    void setx(int a){
        x = a;
    }

    void sety(int a){
        y = a;
    }

};

class WALL{
    private:
    int x = 60,y = 0;

    public:
    void draw(){
        for(int i  = 0;i<25;i++){
            mvprintw(y + i,x,"|");
        }

    }
};

class TANK{
    private:
    int x = 0,y = 15;

    void erase(){
        mvprintw(y - 1,0,"  ");
        mvprintw(y,0,    "  ");
        mvprintw(y + 1,0,"  ");
    }
public: 
    void draw(){
        mvprintw(y- 1,0,"|");
        mvprintw(y,0,    "|-");
        mvprintw(y + 1,0,"|");
    }
    void moveUp(){
        erase();
        y--;
        draw();
    }
    void moveDown(){
        erase();
        y++;
        draw();
    }
    int gety(){
        return y;
    }
};

void initN(){
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr,true);

}     

int main(){

    BULLET b;
    bool shoot = false;
    TANK tank;
    WALL wall;
    wall.draw();
    tank.draw();
        while(true){

            auto key = getch();


            if(key == 'w'){
                tank.moveUp();
            }
            if(key == 's'){
                tank.moveDown();
            }


            if(key == 'k'){
                shoot = true;
                b.setx(3);
                b.sety(tank.gety());
            }

            if(shoot){
                b.shoot();
                if(!b.colision()) {
                    shoot = false;
                    b.erase();}
            }

        }

    endwin();
}