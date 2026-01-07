#pragma once
#include <iostream>
#include <cmath>

namespace bd {

template <typename T>
class Vec2 {
        

    public : 
        T x;
        T y;
        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}  

        Vec2<T> operator+(const Vec2<T>& other) const{
            return Vec2<T>(x + other.x, y + other.y);
        }

        Vec2<T> operator-(const Vec2<T>& other) const{
            return Vec2<T>(x - other.x, y - other.y);
        }

        Vec2<T> operator*(T scalar) const{
            return Vec2<T>(x * scalar, y * scalar);
        }

        Vec2<T> operator/(T scalar) const{
            return Vec2<T>(x / scalar, y / scalar);
        }

        Vec2<T>& operator+=(const Vec2<T>& other){
            x += other.x;
            y += other.y;
            return *this;
        }

        Vec2<T>& operator-=(const Vec2<T>& other){
            x -= other.x;
            y -= other.y;
            return *this; 
        }

        Vec2<T>& operator*=(T scalar){
            x *= scalar; 
            y *= scalar;
            return *this; 
        }

        Vec2<T>& operator/=(T scalar){
            x /= scalar; 
            y /= scalar; 
            return *this; 
        }

        bool operator==(const Vec2<T>& other) const{
            return (x == other.x && y == other.y);
        }

        bool operator!=(const Vec2<T>& other) const{
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& v) {
            os << "(" << v.x << ", " << v.y << ")";
                return os;
        }   

        T norme()const {
            return std::sqrt(x*x + y*y);
        }

        Vec2<T> normalized() const { 
            T n = norme(); 
            if (n == 0) { 
                return Vec2<T>(0, 0);
                } 
            return Vec2<T>(x / n, y / n);
        }

        static Vec2<float> randomUnit() { 
            float angle = (float(rand()) / RAND_MAX) * 2.f * 3.1415926f; 
            return Vec2<float>(std::cos(angle), std::sin(angle)); 
        }



};

} // namespace bd