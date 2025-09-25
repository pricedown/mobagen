#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>
bool RecursiveBacktrackerExample::Step(World* w) {
  // todo: implement this

  // stop and start cases
  if (stack.empty()) {
    if (visited.empty()) {
      Point2D start = randomStartPoint(w);
      if (start.x == INT_MAX)
        return false;
      stack.push(start);
    }
    else {
      return false;
    }
  }

  visited.insert(Point2D(stack.top().x, stack.top().y));

  auto visitableNeighbors = getVisitables(w, stack.top());

  if (visitableNeighbors.empty()) {
    w->SetNodeColor(stack.top(), Color::Black);
    stack.pop();
  } else {
    Point2D nextNeighbor = visitableNeighbors[Random::Range(0, visitableNeighbors.size() - 1)];
    w->SetBetween(stack.top(), nextNeighbor, false);
    w->SetNodeColor(stack.top(), Color::DarkRed);
    w->SetNodeColor(nextNeighbor, Color::Green);
    stack.emplace(nextNeighbor.x, nextNeighbor.y);
  }

  return true;
}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack = std::stack<Point2D>();
  auto sideOver2 = world->GetSize() / 2;

  visited.clear();
}

Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited.contains(Point2D(x, y))) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  int sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  // todo: implement this
  std::vector<Point2D> const neighborOffsets = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  for (Point2D neighborOffset : neighborOffsets) {
    Point2D neighbor = p + neighborOffset;
    bool outOfBounds = neighbor.x < -sideOver2 || neighbor.x > sideOver2 || neighbor.y < -sideOver2 || neighbor.y > sideOver2;
    if (outOfBounds) continue;

    if (!visited.contains(Point2D(neighbor.x, neighbor.y))) visitables.push_back(neighbor);
  }

  return visitables;
}
