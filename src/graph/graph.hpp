/**
 * @file graph.hpp
 * @author dolayer (dolayer@163.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <geometry>
#include <vector>
#include <map>
#include <memory>

namespace mrmp{
    using direction_edge = std::pair<point2d ,point2d >; //first: start point,second: end point
    using std::map;

    class graph
    {
    public:
        graph() =delete;
        graph(const vector<direction_edge>& direction_edges);

        multi_point2d get_vertex_neighors(const point2d& p) const; 
        multi_point2d get_vectices() const;
        
    private:
        class impl;
        std::unique_ptr<impl> m_pimpl;
    };
}


#endif