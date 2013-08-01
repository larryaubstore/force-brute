#include "Renderer.h"

Renderer::Renderer(std::string filename) {
  this->_filename = filename;
}

Renderer::~Renderer() {

}

void Renderer::BlitSurface() {

}

void Renderer::ZoomSurface() {

}

SDL_Surface* Renderer::LoadSurface(std::string fileName) {
  SDL_Surface* surface;
  SDL_RWops* temp_rwop;
  FILE *fp = fopen(fileName.data(), "rb");
  if( fp == NULL ) {
    SDL_SetError("Couldn't open %s", fp);
  } else {
    temp_rwop = SDL_RWFromFP(fp, 0);
    surface = IMG_Load_RW(temp_rwop, 0);

    SDL_FreeRW(temp_rwop);
    temp_rwop = NULL;
    fclose(fp);
    return surface;
  }
  return NULL;
}

void Renderer::FreeSurface() {

}

void Renderer::FlipSurface() {

}

void Renderer::Run() {

}

std::vector<SurfaceSharedPtr<SDL_Surface>::type> Renderer::GetLoadedSurfaces() {
  std::vector<SurfaceSharedPtr<SDL_Surface>::type> vect;
  return vect;
}

DynamicGridSharedPtr Renderer::GetDynamicGrid() {
  return DynamicGridSharedPtr();
}
