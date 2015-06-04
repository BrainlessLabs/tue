`tue::mat::set_column`
======================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C, int R>
template<typename I>
void mat<T, C, R>::set_column(const I& i, const vec<T, R>& column) noexcept;
```

Sets the value of column `i` of this [`mat`](../../headers/mat.md) to that of
the given [`vec`](../../headers/vec.md). No bounds checking is performed.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.