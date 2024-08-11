#pragma once 

#include "GameObject.h"
#include "InputHandler.h"
#include "Defines.h"
#include "LoaderParams.h"



class MenuButton : public Object::GameObject {
public:
  MenuButton(const LoaderParams* params, void (*callback)());

  virtual void draw();
  virtual void update();
  virtual void clean();

  bool released;

  static void menuToPlay();
  static void exitFromMenu();

private:
  enum button_state
  {
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    CLICKED = 2
  };

  void (*callback)();
};

