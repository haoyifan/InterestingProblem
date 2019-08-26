#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>

namespace mincut {

    typedef unsigned Vertex;

    typedef unsigned Weight;

#define WEIGHT_NONE 0
#define WEIGHT_MAX ((unsigned)0 - 1)

#define INITIALIZE_FROM_FILE (true)

    class Graph {
        public:
            Graph() = default;


            ~Graph() = default;

            void init(std::string &file);

            void dump();

            Weight get_mincut();

        private:

            void construct(std::string &p);
            void construct_graph(std::fstream &graph_stream);
            void construct_vertex(std::string &line);
            bool _find_any_path(Vertex u, Vertex v, std::vector<Vertex> &p);
            bool path_has_vertex(std::vector<Vertex> &p, Vertex v);
            void apply_residual(std::vector<Vertex> &p);
            Vertex get_source();
            Vertex get_sink();
            unsigned get_size();
            void set_source(Vertex s);
            void set_sink(Vertex t);
            void set_size(unsigned n);
            void set_weight(Vertex u, Vertex v, Weight w);
            bool find_any_path(Vertex u, Vertex v, std::vector<Vertex> &p);

            std::vector<std::unique_ptr<Vertex>> m_vertices;
            std::vector<std::vector<Weight>> m_graph;
            unsigned N;
            Vertex m_source, m_sink;
            Weight mincut;
    };
};

#endif
