#pragma once

#include "inner_product.hpp"
#include "line.hpp"
#include "meet.hpp"
#include "plane.hpp"
#include "point.hpp"

namespace kln
{
/// \defgroup proj Projections
///
/// Projections in Geometric Algebra take on a particularly simple form.
/// For two geometric entities $a$ and $b$, the projection of $a$ on $b$
/// is given by:
///
/// $$ \textit{proj}_b a = (a \cdot b) \wedge b $$
///
/// The inner product can be thought of as the part of $b$ _least like_ $a$.
/// Using the meet operator on this part produces the part of $b$ _most like_
/// $a$. A simple sanity check is to consider the grades of the result. If the
/// grade of $b$ is less than the grade of $a$, we end up with an entity with
/// grade $a - b + b = a$ as expected.

/// \addtogroup proj
/// @{

/// Project a point onto a line
inline point KLN_VEC_CALL project(point a, line b) noexcept
{
    return {(a | b) ^ b};
}

/// Project a point onto a plane
inline point KLN_VEC_CALL project(point a, plane b) noexcept
{
    return {(a | b) ^ b};
}

/// Project a line onto a plane
inline line KLN_VEC_CALL project(line a, plane b) noexcept
{
    return {(a | b) ^ b};
}
/// @}
} // namespace kln
