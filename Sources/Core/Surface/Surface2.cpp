// This code is based on Jet framework.
// Copyright (c) 2018 Doyub Kim
// CubbyFlow is voxel-based fluid simulation engine for computer games.
// Copyright (c) 2020 CubbyFlow Team
// Core Part: Chris Ohk, Junwoo Hwang, Jihong Sin, Seungwoo Yoo
// AI Part: Dongheon Cho, Minseo Kim
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Core/Surface/Surface2.hpp>

namespace CubbyFlow
{
Surface2::Surface2(const Transform2& transform_, bool isNormalFlipped_)
    : transform(transform_), isNormalFlipped(isNormalFlipped_)
{
    // Do nothing
}

Surface2::Surface2(const Surface2& other)
    : transform(other.transform), isNormalFlipped(other.isNormalFlipped)
{
    // Do nothing
}

Surface2::~Surface2()
{
    // Do nothing
}

Vector2D Surface2::ClosestPoint(const Vector2D& otherPoint) const
{
    return transform.ToWorld(ClosestPointLocal(transform.ToLocal(otherPoint)));
}

BoundingBox2D Surface2::BoundingBox() const
{
    return transform.ToWorld(BoundingBoxLocal());
}

bool Surface2::Intersects(const Ray2D& ray) const
{
    return IntersectsLocal(transform.ToLocal(ray));
}

double Surface2::ClosestDistance(const Vector2D& otherPoint) const
{
    return ClosestDistanceLocal(transform.ToLocal(otherPoint));
}

SurfaceRayIntersection2 Surface2::ClosestIntersection(const Ray2D& ray) const
{
    auto result = ClosestIntersectionLocal(transform.ToLocal(ray));

    result.point = transform.ToWorld(result.point);
    result.normal = transform.ToWorldDirection(result.normal);
    result.normal *= (isNormalFlipped) ? -1.0 : 1.0;

    return result;
}

Vector2D Surface2::ClosestNormal(const Vector2D& otherPoint) const
{
    auto result = transform.ToWorldDirection(
        ClosestNormalLocal(transform.ToLocal(otherPoint)));
    result *= (isNormalFlipped) ? -1.0 : 1.0;
    return result;
}

void Surface2::UpdateQueryEngine()
{
    // Do nothing
}

bool Surface2::IntersectsLocal(const Ray2D& ray) const
{
    auto result = ClosestIntersectionLocal(ray);
    return result.isIntersecting;
}

double Surface2::ClosestDistanceLocal(const Vector2D& otherPoint) const
{
    return otherPoint.DistanceTo(ClosestPointLocal(otherPoint));
}
}  // namespace CubbyFlow