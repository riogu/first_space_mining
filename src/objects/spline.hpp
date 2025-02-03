#ifndef SPLINE_HPP
#define SPLINE_HPP

#include "raylib.h"
#include <memory>
#include <vector>

class SplineSegment {
  public:
    Color color;
    std::vector<Vector2> points;

    SplineSegment() {}

    virtual void draw();
    virtual void drawSplineColor(Color SplineColor);
    // might need later
    // virtual Vector2 GetSplinePoint();
    virtual ~SplineSegment() {}
};

class SplineSegmentCatmullRom : public SplineSegment {
  public:
    SplineSegmentCatmullRom(Vector2 point1, Vector2 point2, Vector2 point3, Vector2 point4) {
        points.push_back(point1);
        points.push_back(point2);
        points.push_back(point3);
        points.push_back(point4);
    }
    void draw() {
        DrawSplineSegmentCatmullRom(points[0], points[1], points[2], points[3], 1.0f, color);
    }
    virtual void drawSplineColor(Color SplineColor) {
        DrawSplineSegmentCatmullRom(points[0], points[1], points[2], points[3], 1.0f, SplineColor);
    }
};

class SplineSegmentBezierCubic : public SplineSegment {
  public:
    SplineSegmentBezierCubic(Vector2 point1, Vector2 point2, Vector2 point3, Vector2 point4) {
        points.push_back(point1);
        points.push_back(point2);
        points.push_back(point3);
        points.push_back(point4);
    }
    void draw() {
        DrawSplineSegmentBezierCubic(points[0], points[1], points[2], points[3], 1.0f, color);
    }
    virtual void drawSplineColor(Color SplineColor) {
        DrawSplineSegmentBezierCubic(points[0], points[1], points[2], points[3], 1.0f, SplineColor);
    }
};

class Spline {
  public:
    std::vector<std::shared_ptr<SplineSegment>> spline_segments;
    Color color;

    Spline(Color color) : color(color) {}

    virtual void add_segment(std::shared_ptr<SplineSegment> segment) {
        spline_segments.push_back(segment);
    }
    void draw() {
        for (auto &segment : spline_segments) {
            segment->draw();
        }
    }
    virtual ~Spline() {}
};

class SplineCatmullRom : public Spline {
  public:
    SplineCatmullRom(Color color) : Spline(color) {}

    void add_segment(std::shared_ptr<SplineSegment> segment) { spline_segments.push_back(segment); }
};

class SplineBezierCubic : public Spline {
  public:
    SplineBezierCubic(Color color) : Spline(color) {}

    void add_segment(std::shared_ptr<SplineSegment> segment) { spline_segments.push_back(segment); }
};

#endif
