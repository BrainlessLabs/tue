`tue::rect` equality operator
=============================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
// lhs == rhs
template<typename P, typename S, typename OtherP, typenrmae OtherS>
constexpr bool operator==(
    const rect<P, S>& lhs,
    const rect<OtherP< OtherS>& rhs) noexcept;
```

Returns `true` if the `position`'s and `size`'s of two
[`rect`](../../headers/rect.md)'s compare equal and `false` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.