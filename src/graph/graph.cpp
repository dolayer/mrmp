/**
 * @file graph.cpp
 * @author dolayer (dolayer@163.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "graph.hpp"
#include <algorithm>

namespace mrmp
{
    graph::graph(const vector<direction_edge>& direction_edges):
        m_pimpl(std::make_unique<impl>(direction_edges))
    {
        
    }

    multi_point2d graph::get_vertex_neighors(const point2d& p) const
    {
        return m_pimpl->get_vertex_neighors(p);
    }

    multi_point2d graph::get_vectices() const
    {
        return m_pimpl->get_vectices();
    }

    /**
    * @brief graph impl 
    */
    class graph::impl
    {
    public:
        impl(const vector<direction_edge>& direction_edges);
        multi_point2d get_vertex_neighors(const point2d& p) const; 
        multi_point2d get_vectices() const;
    
    private:
        point2d get_vertex(int index) const;
        int get_index(const point2d& p) const;

    private:
        multi_point2d m_vertices; 
        map<int,vector<int>> m_vertex_neighbors_list;
    };

    graph::impl::impl(const vector<direction_edge>& direction_edges)
    {
        for(const auto& edge:direction_edges){
            if(std::find(m_vertices.begin(),m_vertices.end(),edge.first) == m_vertices.end()){
                m_vertices.emplace_back(edge.first);
            }

            if(std::find(m_vertices.begin(),m_vertices.end(),edge.second) == m_vertices.end()){
                m_vertices.emplace_back(edge.first);
            }
        }

        for (int i = 0; i < m_vertices.size(); i++) {
            m_vertex_neighbors_list[i] = {};
        }

        for(const auto& edge:direction_edges){
            int first_index = get_index(edge.first);
            int second_index = get_index(edge.second);
            m_vertex_neighbors_list[first_index].emplace_back(second_index);
        }
    }

    multi_point2d graph::impl::get_vertex_neighors(const point2d& p) const
    {
        multi_point2d neighors;
        int index = get_index(p);
        auto const iter = m_vertex_neighbors_list.find(index);
        if(iter != m_vertex_neighbors_list.end()){
            vector<int> index_neighbors =iter->second;
            for(auto index_neighbor:index_neighbors){
                point2d neighor = get_vertex(index_neighbor);
                neighors.emplace_back(neighor);
            }
        }
    }

    multi_point2d graph::impl::get_vectices() const
    {
        return m_vertices;
    }

    int graph::impl::get_index(const point2d& p) const
    {
        int index = -1;
        auto iter = std::find(m_vertices.begin(),m_vertices.end(),p);

        if(iter != m_vertices.end()){
            index = std::distance(m_vertices.begin(),iter);
        }
        return index;
    }
}