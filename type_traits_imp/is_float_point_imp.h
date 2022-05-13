template <typename T>
struct is_float_point
{
    enum {value = false};
};

template <>
struct is_float_point<float>
{
    enum {value = true};
};

template <>
struct is_float_point<double>
{
    enum {value = true};
};

template <>
struct is_float_point<long double>
{
    enum {value = true};
};
