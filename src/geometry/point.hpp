/**
 * @file point.hpp
 * @author dolayer (dolayer@163.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __POINT_HPP__
#define __POINT_HPP__
#include <vector>

using std::vector;
namespace mrmp
{
    template<typename T>
    class point2
    {
    public:
        point2(T x,T y) { m_x= x;m_y= y; }  
        point2() = default;
        point2(const point2& ) =default;
        point2(point2&& ) =default;
        point2& operator=(const point2& ) =default;
        point2& operator=(point2&& ) =default;

        inline T x() const noexcept { return m_x; }

        inline T y() const noexcept{ return m_y; }

        inline void set_x(T x) noexcept { m_x= x; }

        inline void set_y(T x) noexcept { m_x = y; }

        friend bool operator==(const point2 &p1, const point2 &p2) noexcept { return p1.m_x == p2.m_x && p1.m_y==p2.m_y; }

        friend bool operator!=(const point2 &p1, const point2 &p2) noexcept { return p1.m_x != p2.m_x || p1.m_y!=p2.m_y; }
        
    private:
        T m_x;
        T m_y;

    };

    template<typename T>
    class point3
    {
    public:
        point3(T x,T y,T z) { m_x = x; m_y = y; m_z = z; }  
        point3() = default;
        point3(const point3& ) =default;
        point3(point3&& ) =default;
        point3& operator=(const point3& ) =default;
        point3& operator=(point3&& ) =default;

        inline T x() const noexcept { return m_x; }

        inline T y() const noexcept{ return m_y; }

        inline void set_x(T x) noexcept { m_x= x; }

        inline void set_y(T x) noexcept { m_x = y; }

        friend bool operator==(const point3 &p1, const point3 &p2) noexcept { 
            return p1.m_x == p2.m_x && p1.m_y==p2.m_y && p1.m_z ==p2.m_z; 
        }

        friend bool operator!=(const point3 &p1, const point3 &p2) noexcept { 
            return p1.m_x != p2.m_x || p1.m_y!=p2.m_y || p1.m_z != p2.m_z; 
        }
        
    private:
        T m_x;
        T m_y;
        T m_z;

    };

    using point2i = point2<int>;
    using point2f = point2<float>;
    using point2d = point2<double>;
    using point3i = point3<int>;
    using point3f = point2<float>;
    using point3d = point2<double>;
    using multi_point2i = vector<point2i>;
    using multi_point2f = vector<point2f>;
    using multi_point2d = vector<point2d>;
    using multi_point3i = vector<point3i>;
    using multi_point3f = vector<point3f>;
    using multi_point3d = vector<point3d>;
}
#endif