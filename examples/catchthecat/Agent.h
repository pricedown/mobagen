#ifndef AGENT_H
#define AGENT_H
#include "math/Point2D.h"
#include <vector>
#include <algorithm>

class World;

class Agent {
public:
  explicit Agent() = default;

  int hueristic(Point2D& p, int sideSizeOver2) {
    int x = abs(p.x);
    int y = abs(p.y);

    return std::min({sideSizeOver2 - abs(p.x), sideSizeOver2 - abs(p.y)});
  }

  virtual Point2D Move(World*) = 0;

  std::vector<Point2D> generatePath(World* w);
};

#endif  // AGENT_H
