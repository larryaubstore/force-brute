#include "Renderer.h"

Renderer::Renderer(DynamicGridSharedPtr dynamicGridSharedPtr) {
  this->_dynamicGridSharedPtr = dynamicGridSharedPtr;
}

Renderer::~Renderer() {

}

void Renderer::BlitSurface() {

}

void Renderer::ZoomSurface() {

}

void Renderer::LoadSurface() {

}

void Renderer::FreeSurface() {

}

void Renderer::FlipSurface() {

}

std::vector<SurfaceSharedPtr<SDL_Surface>::type> Renderer::GetLoadedSurfaces() {
  std::vector<SurfaceSharedPtr<SDL_Surface>::type> vect;
  return vect;
}

DynamicGridSharedPtr Renderer::GetDynamicGrid() {
  return DynamicGridSharedPtr();
}
