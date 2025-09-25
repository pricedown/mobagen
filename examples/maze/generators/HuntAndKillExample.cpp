#include "HuntAndKillExample.h"
#include "../World.h"
#include "Random.h"
#include <climits>
bool HuntAndKillExample::Step(World* w) {
  // todo: code this
  int sideOver2 = w->GetSize() / 2;

  if (!stack.empty()) {
    // killing

    Point2D current = stack.top();

    auto visitables = getVisitables(w, current);
    if (!visitables.empty()) {
      // choose a random unvisited neighbor
    } else {
      // backtrack
    }

    return true;
  }

  // hunting
  for (int y = -sideOver2; y <= sideOver2; y++) {
    for (int x = -sideOver2; x <= sideOver2; x++) {
      if (!visited[y][x]) {
          return true;
      }
    }
  }

}
void HuntAndKillExample::Clear(World* world) {
  visited.clear();
  stack = std::stack<Point2D>();

  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D HuntAndKillExample::randomStartPoint(World* world) {
  // Todo: improve this if you want
  auto sideOver2 = world->GetSize() / 2;

  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> HuntAndKillExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  // todo: code this
  std::vector<Point2D> const neighborOffsets = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  for (auto& delta : neighborOffsets) {
    int nx = p.x + delta.x;
    int ny = p.y + delta.y;

    if (nx >= -sideOver2 && nx <= sideOver2 && ny >= -sideOver2 && ny <= sideOver2) {
      if (!visited[ny][nx]) {
        visitables.push_back({nx, ny});
      }
    }
  }

  return visitables;
}
std::vector<Point2D> HuntAndKillExample::getVisitedNeighbors(World* w, const Point2D& p) {
  std::vector<Point2D> deltas = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> neighbors;

  // todo: code this
  std::vector<Point2D> const neighborOffsets = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  for (auto& delta : neighborOffsets) {
    int nx = p.x + delta.x;
    int ny = p.y + delta.y;

    if (nx >= -sideOver2 && nx <= sideOver2 && ny >= -sideOver2 && ny <= sideOver2) {
      if (visited[ny][nx]) {
        neighbors.push_back({nx, ny});
      }
    }
  }

  return neighbors;
}
