#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "def.h"
#include "sdlutils.h"
#include "resourceManager.h"
#include "commander.h"

// Globals
SDL_Surface *Globals::g_screenOutput = NULL;
SDL_Surface *Globals::g_screen = NULL;
const SDL_Color Globals::g_colorTextNormal = {COLOR_TEXT_NORMAL};
const SDL_Color Globals::g_colorTextTitle = {COLOR_TEXT_TITLE};
const SDL_Color Globals::g_colorTextDir = {COLOR_TEXT_DIR};
const SDL_Color Globals::g_colorTextSelected = {COLOR_TEXT_SELECTED};
std::vector<CWindow *> Globals::g_windows;

int main(int argc, char** argv)
{
    // Avoid crash due to the absence of mouse
    {
        char l_s[]="SDL_NOMOUSE=1";
        putenv(l_s);
    }

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cerr << "Couldn't initialize SDL: " <<  SDL_GetError() << std::endl;
        return 1;
    }

    // Screen
    Globals::g_screenOutput = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SURFACE_FLAGS);
    if (Globals::g_screenOutput == NULL)
    {
        std::cerr << "SDL_SetVideoMode failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    Globals::g_screen = SDL_CreateRGBSurface(SDL_HWSURFACE, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    if (Globals::g_screen == NULL)
    {
        std::cerr << "SDL_CreateRGBSurface failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Hide cursor
    SDL_ShowCursor(SDL_DISABLE);

    // Init font
    if (TTF_Init() == -1)
    {
        std::cerr << "TTF_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create instances
    CResourceManager::instance();
    char *home = getenv("HOME");
    std::string l_path = home ? home : PATH_DEFAULT;
    CCommander l_commander(l_path, l_path);

    // Main loop
    l_commander.execute();

    //Quit
    SDL_utils::hastalavista();

    return 0;
}
