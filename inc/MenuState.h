#include "GameStates.h"

namespace States {
class MenuState : public GameStates {
public:
  virtual void update();
  virtual void render();
  virtual bool onEnter();
  virtual bool onExit();
  virtual std::string getStateID() const { return menuId; }
private:
  static const std::string menuId;
};
}
