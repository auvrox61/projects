#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define MAX_PLAYERS 3
#define MAX_ZOMBIES 3
#define MAX_FRAMES 5
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 300
#define GRAVITY 0.98f
#define ISGRAVITYACTIVE 1

typedef struct{
    int id;
    float x,y;
    float vx,vy;
    int health;
    int healthDecayPF;
    int active;
} players;

typedef struct{
    int id;
    float x,y;
    float vx,vy;
    int health;
    int healthDecayPF;
    int active;
} zombies;

void updatePlayerStatus(players *p){
    p->x+=p->vx;
    p->y+=p->vy;
    if(ISGRAVITYACTIVE){
        p->vy+=GRAVITY;
    }
    p->health-=p->healthDecayPF;
    if(p->x<0||p->x>SCREEN_WIDTH||p->y<0||p->y>SCREEN_HEIGHT){
        p->active=0;
    }
}

void updateZombieStatus(zombies *z){
    z->x+=z->vx;
    z->y+=z->vy;
    if(ISGRAVITYACTIVE){
        z->vy+=GRAVITY;
    }
    z->health-=z->healthDecayPF;
    if(z->x<0||z->x>SCREEN_WIDTH||z->y<0||z->y>SCREEN_HEIGHT){
        z->active=0;
    }
}

void determineCollision(players player[],zombies zombie[]){
    for(int i=0;i<MAX_PLAYERS;i++){
        for(int j=0;j<MAX_ZOMBIES;j++){
            if(!(player[i].active)||!(zombie[j].active)){
                continue;
            }
            if(((int)player[i].x==(int)zombie[j].x)||(int)player[i].y==(int)zombie[j].y){
                if(player[i].health>zombie[j].health){
                    zombie[j].active=0;
                } else if(player[i].health<zombie[j].health){
                    player[i].active=0;
                } else{
                    player[i].active=0;
                    zombie[j].active=0;
                }
            }
        }
    }
}

void determineWinner(players p[],zombies z[]){
    int playerNum=0;
    int zombieNum=0;

    for(int i=0;i<MAX_PLAYERS;i++){
        if(p[i].active){
            playerNum++;
        }
    }

    for(int i=0;i<MAX_ZOMBIES;i++){
        if(z[i].active){
            zombieNum++;
        }
    }

    if(zombieNum>playerNum){
        printf("You Lose!Zombies Take Over the Island and Kill every People\n");
    } else if(zombieNum<playerNum){
        printf("You Win!Peace has been Restored Over the Island\n");
    } else{
        printf("Threat Looms Over the Island!Play Again and try to Save the Island!\n");
    }
}


int main(){
    players player[MAX_PLAYERS];
    zombies zombie[MAX_ZOMBIES];

    for(int i=0;i<MAX_PLAYERS;i++){
        printf("Enter Player ID : \n");
        scanf("%d",&player[i].id);
        printf("Enter Further Details for Player #%d :\n",player[i].id);
        printf("Enter Positions (X,Y) :\n");
        scanf("%f %f",&player[i].x,&player[i].y);
        printf("Enter Axiswise Velocities (X,Y) :\n");
        scanf("%f %f",&player[i].vx,&player[i].vy);
        printf("Enter Health Rating :\n");
        scanf("%d",&player[i].health);
        printf("Enter Health Decay Rate (Per Frame) :\n");
        scanf("%d",&player[i].healthDecayPF);
        player[i].active=1;
    }

    for(int i=0;i<MAX_ZOMBIES;i++){
        printf("Enter Zombie ID : \n");
        scanf("%d",&zombie[i].id);
        printf("Enter Further Details for Zombie #%d :\n",zombie[i].id);
        printf("Enter Positions (X,Y) :\n");
        scanf("%f %f",&zombie[i].x,&zombie[i].y);
        printf("Enter Axiswise Velocities (X,Y) :\n");
        scanf("%f %f",&zombie[i].vx,&zombie[i].vy);
        printf("Enter Health Rating :\n");
        scanf("%d",&zombie[i].health);
        printf("Enter Health Decay Rate (Per Frame) :\n");
        scanf("%d",&zombie[i].healthDecayPF);
        zombie[i].active=1;
    }

    for(int i=1;i<=MAX_FRAMES;i++){
        for(int j=0;j<MAX_PLAYERS;j++){
            updatePlayerStatus(&player[j]);
        }
        for(int j=0;j<MAX_ZOMBIES;j++){
            updateZombieStatus(&zombie[j]);
        }
        determineCollision(player,zombie);
        Sleep(1500);
    }
    determineWinner(player,zombie);
    return 0;
}
