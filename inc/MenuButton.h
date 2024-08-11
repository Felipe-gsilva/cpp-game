#pragma once 

#include "GameObject.h"
#include "InputHandler.h"
#include "Defines.h"
#include "LoaderParams.h"

using namespace Object;

class MenuButton : public GameObject {
public:
  MenuButton(const LoaderParams* params);

  virtual void draw();
  virtual void update();
  virtual void clean();

private:
  enum button_state
  {
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    CLICKED = 2
  };
};

