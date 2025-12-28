#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 900
#define HEIGHT 600

int scale = 10;

typedef struct {
    int vx, vy;
} Velocity;

typedef struct {
    int x, y;
    Uint32 rgb;
} Agent;

void move_agents(SDL_Surface *psurface)
{
    Velocity val = get rand_v()

}

Velocity get_rand_v()
{
    int choice = rand() / (RAND_MAX/4);
    printf("%d\n", choice);
    switch(choice)
    {
        case 0: //up
            return (Velocity) {0, -1}; 
        case 1: //down
            return (Velocity) {0, 1};
        case 2: //left
            return (Velocity) {-1, 0};
        case 3: //right
            return (Velocity) {1, 0};
    }
    fprintf(stderr, "Impossible random vale %d encountered\n", choice);
    exit(-1);
}

int main(int argcount, const char *argval[])
{
    int num_agents;
    if(argcount == 1)
    {
        num_agents = 5;
    }
    else if(argcount == 2)
    {
        num_agents = atoi(argval[1]);
    }
    else
    {
        printf("Usage: %s <num-of-agents>\n", argval[0]);
        return -1;
    }

    srand(time(NULL));

    SDL_Window *pwindow = SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); 
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    
    SDL_Rect rect = (SDL_Rect) {WIDTH/2, HEIGHT/2, 2, 2};
    Agents *pagents = calloc(num_agents, sizeof(Agents));

    int app_running = 1;
    while(app_running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                app_running = 0;
            }
        }

        move_agents();
        Velocity vel = get_rand_v();
        for(int i=0; i<scale; i++)
        {
            rect.x += vel.vx;
            rect.y += vel.vy;
            SDL_FillRect(psurface, &rect, 0xFFFFFF);
        }
        SDL_UpdateWindowSurface(pwindow);
        SDL_Delay(20);
    }
}
