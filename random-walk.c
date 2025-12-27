#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 900
#define HEIGHT 600

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
    }

    SDL_Window *pwindow = SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); 
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    SDL_Rect rect = (SDL_Rect) {50, 50, 50, 50};
    SDL_FillRect(psurface, &rect, 0xFFFFFF);

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
    }
}
