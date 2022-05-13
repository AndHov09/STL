template <typename T>
struct is_integral
{
    enum {value = false};
};

template <>
struct is_integral<bool>
{
    enum {value = true};
};

template <>
struct is_integral<char>
{
    enum {value = true};
};

template <>
struct is_integral<char16_t>
{
    enum {value = true};
};

template <>
struct is_integral<char32_t>
{
    enum {value = true};
};

template <>
struct is_integral<wchar_t>
{
    enum {value = true};
};

template <>
struct is_integral<signed char>
{
    enum {value = true};
};

template <>
struct is_integral<short int>
{
    enum {value = true};
};

template <>
struct is_integral<int>
{
    enum {value = true};
};

template <>
struct is_integral<long int>
{
    enum {value = true};
};

template <>
struct is_integral<long long int>
{
    enum {value = true};
};

template <>
struct is_integral<unsigned char>
{
    enum {value = true};
};

template <>
struct is_integral<unsigned short int>
{
    enum {value = true};
};

template <>
struct is_integral<unsigned int>
{
    enum {value = true};
};

template <>
struct is_integral<unsigned long int>
{
    enum {value = true};
};

template <>
struct is_integral<unsigned long long int>
{
    enum {value = true};
};
