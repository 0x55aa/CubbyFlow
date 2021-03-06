// This code is based on Jet framework.
// Copyright (c) 2018 Doyub Kim
// CubbyFlow is voxel-based fluid simulation engine for computer games.
// Copyright (c) 2020 CubbyFlow Team
// Core Part: Chris Ohk, Junwoo Hwang, Jihong Sin, Seungwoo Yoo
// AI Part: Dongheon Cho, Minseo Kim
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Core/Surface/ImplicitSurface3.hpp>

namespace CubbyFlow
{
ImplicitSurface3::ImplicitSurface3(const Transform3& transform,
                                   bool isNormalFlipped)
    : Surface3(transform, isNormalFlipped)
{
    // Do nothing
}

ImplicitSurface3::ImplicitSurface3(const ImplicitSurface3& other)
    : Surface3(other)
{
    // Do nothing
}

ImplicitSurface3::~ImplicitSurface3()
{
    // Do nothing
}

double ImplicitSurface3::SignedDistance(const Vector3D& otherPoint) const
{
    return SignedDistanceLocal(transform.ToLocal(otherPoint));
}

double ImplicitSurface3::ClosestDistanceLocal(const Vector3D& otherPoint) const
{
    return std::fabs(SignedDistanceLocal(otherPoint));
}
}  // namespace CubbyFlow