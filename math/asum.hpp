#pragma once

// arithmetic progression sum
// first : a, difference : d, length : n
template <typename T>
T asum(T first, T diff, T len)
{
    return first * len + (len - 1) * len / 2 * diff;
}