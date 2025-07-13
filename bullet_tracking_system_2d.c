#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define MAX_BULLETS 5
#define MAX_FRAMES 10
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 300
#define GRAVITY 0.98f
#define GRAVITYACT 1

typedef struct{
    int id;
    float x,y;
    float vx,vy;
    int damage;
    int damageDecayPF;
    int active;
    int lifespan;
    int destructionFlag;
} bullets;

void updateBullet(bullets *b){
    if(!(b->active)){
        return;
    } else{
        b->x+=b->vx;
        b->y+=b->vy;
        if(GRAVITYACT){
            b->vy+=GRAVITY;
        }
        b->damage-=b->damageDecayPF;
        b->lifespan--;
        if(b->x<0||b->x>SCREEN_WIDTH||b->y<0||b->y>SCREEN_HEIGHT||b->damage<=0||b->lifespan<=0){
            b->active=0;
        }
    }
}

void printBulletStatus(bullets *b){
    if(!(b->active)){
        if(!(b->destructionFlag)){
            printf("Bullet #%d is destroyed\n",b->id);
            b->destructionFlag=1;
        }
    } else{
        printf("-------------------------------------------------------\n");
        printf("Bullet %d Information :\nBullet Positions : (%.2f,%.2f)\nBullet Velocities (Axiswise) : (%.2f,%.2f)\nBullet Damage : %d\nBullet Lifespan : %d\n",b->id,b->x,b->y,b->vx,b->vy,b->damage,b->lifespan);
        printf("\n");
    }
}

int main(){
    bullets bullet[MAX_BULLETS];
    
    for(int i=0;i<MAX_BULLETS;i++){
        printf("Enter Bullet ID First :\n");
        scanf("%d",&bullet[i].id);
        printf("Enter Further Details for Bullet #%d : \n",bullet[i].id);
        printf("Enter Bullet Positions : \n");
        scanf("%f %f",&bullet[i].x,&bullet[i].y);
        printf("Enter Bullet Velocities (Axiswise) : \n");
        scanf("%f %f",&bullet[i].vx,&bullet[i].vy);
        printf("Enter Bullet Damage Rating : \n");
        scanf("%d",&bullet[i].damage);
        printf("Enter Bullet Damage Decay Rate Per Frame : \n");
        scanf("%d",&bullet[i].damageDecayPF);
        printf("Enter Bullet's Initial Lifespan : \n");
        scanf("%d",&bullet[i].lifespan);
        bullet[i].active=1;
        bullet[i].destructionFlag=0;
    }

    for(int i=1;i<=MAX_FRAMES;i++){
        for(int j=0;j<MAX_BULLETS;j++){
            updateBullet(&bullet[j]);
            printBulletStatus(&bullet[j]);
        }
        Sleep(1500);
    }
    return 0;
}