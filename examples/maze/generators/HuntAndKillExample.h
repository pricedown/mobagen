#ifndef HUNTANDKILLEXAMPLE_H
#define HUNTANDKILLEXAMPLE_H

#include "../MazeGeneratorBase.h"
#include "math/Point2D.h"
#include <map>
#include <vector>
#include <stack>

class HuntAndKillExample : public MazeGeneratorBase {
private:
  std::stack<Point2D> stack;
  std::map<int, std::map<int, bool>> visited;  // naive. not optimal
  Point2D randomStartPoint(World* world);
  std::vector<Point2D> getVisitables(World* w, const Point2D& p);
  std::vector<Point2D> getVisitedNeighbors(World* w, const Point2D& p);

public:
  HuntAndKillExample() = default;
  std::string GetName() override { return "HuntAndKill"; };
  bool Step(World* world) override;
  void Clear(World* world) override;
};

#endif  // HUNTANDKILLEXAMPLE_H
