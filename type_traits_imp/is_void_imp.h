#ifndef _IS_SAME_
#define _IS_SAME_

template <typename T,typename U>
struct is_same
{
    enum {value = false};
};

template <typename T>
struct is_same<T,T>
{
    enum {value = true};
};

#endif // _IS_SAME_
