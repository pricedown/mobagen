#ifndef RECURSIVEBACKTRACKER_H
#define RECURSIVEBACKTRACKER_H

#include "../MazeGeneratorBase.h"
#include "math/Point2D.h"
#include <map>
#include <stack>
#include <unordered_set>
#include <vector>

class RecursiveBacktrackerExample : public MazeGeneratorBase {
private:
  std::stack<Point2D> stack;
  std::unordered_set<Point2D> visited;  // naive. not optimal
  Point2D randomStartPoint(World* world);
  std::vector<Point2D> getVisitables(World* w, const Point2D& p);

public:
  RecursiveBacktrackerExample() = default;
  std::string GetName() override { return "Recursive Back-Tracker"; };
  bool Step(World* world) override;
  void Clear(World* world) override;
};

#endif  // RECURSIVEBACKTRACKER_H
