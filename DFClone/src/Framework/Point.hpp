//
// Created by rusla on 31.12.2023.
//

#ifndef POINT_HPP
#define POINT_HPP

namespace Framework
{
    template<typename T>
    struct Point
    {
        T x;
        T y;

        Point();
        Point(T x, T y);

        Point& operator+=(const Point& other);
        Point& operator*=(const Point& other);
        Point& operator/=(const Point& other);

        Point& operator*=(T factor);

        template<typename U>
        operator Point<U>() const;
    };

    template<typename T>
    Point<T> operator+(const Point<T>& a, const Point<T>& b);

    template<typename T>
    Point<T> operator*(const Point<T>& a, const Point<T>& b);

    template<typename T>
    Point<T> operator/(const Point<T>& a, const Point<T>& b);

    template<typename T>
    Point<T> operator*(const Point<T>& a, T f);

    template<typename T, typename U>
    Point<U> operator*(const Point<T>& a, U f);

    template<typename T>
    Point<T>::Point()
        : x(T()), y(T())
    {
    }

    template<typename T>
    Point<T>::Point(T x, T y)
        : x(x), y(y)
    {
    }

    template<typename T>
    Point<T>& Point<T>::operator+=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    template<typename T>
    Point<T>& Point<T>::operator*=(const Point& other)
    {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    template<typename T>
    Point<T>& Point<T>::operator/=(const Point& other)
    {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    template<typename T>
    Point<T>& Point<T>::operator*=(T factor)
    {
        this->x *= factor;
        this->y *= factor;
        return *this;
    }

    template<typename T>
    template<typename U>
    Point<T>::operator Point<U>() const
    {
        return {U(this->x), U(this->y)};
    }

    template<typename T>
    Point<T> operator+(const Point<T>& a, const Point<T>& b)
    {
        Point<T> a1(a);
        a1 += b;
        return a1;
    }

    template<typename T>
    Point<T> operator*(const Point<T>& a, const Point<T>& b)
    {
        Point<T> a1(a);
        a1 *= b;
        return a1;
    }

    template<typename T>
    Point<T> operator/(const Point<T>& a, const Point<T>& b)
    {
        Point<T> a1(a);
        a1 /= b;
        return a1;
    }

    template<typename T>
    Point<T> operator*(const Point<T>& a, T f)
    {
        Point<T> a1(a);
        a1 *= f;
        return a1;
    }

    template<typename T, typename U>
    Point<U> operator*(const Point<T>& a, U f)
    {
        return {U(a.x) * f, U(a.y) * f};
    }
}

#endif //POINT_HPP
