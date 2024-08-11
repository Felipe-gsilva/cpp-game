#include "GameStates.h"

namespace States {
class PlayState : public GameStates {
public:
  virtual void update();
  virtual void render();
  virtual bool onEnter();
  virtual bool onExit();
  virtual std::string getStateID() const { return playId; }
private:
  static const std::string playId;
};
}
