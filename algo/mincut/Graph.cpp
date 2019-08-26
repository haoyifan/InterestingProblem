#include <fstream>

#include "Graph.h"

using namespace mincut;

void Graph::init(std::string &file) {
    construct(file);
}

/*
 * Input is as follow:
 * 1. The first line is the number of vertices N.
 * 2. The second line contains the id of source and sink
 * 3. Folowing N lines form a NxN matrix, where the value in a cell(u, v)
 *    determines the capacity of u->v.
 */
void Graph::construct(std::string &p) {
    std::fstream graph_stream;
    std::string line;
    graph_stream.open(p.c_str(), std::fstream::in);

    graph_stream >> N;

    assert(N > 0);

    graph_stream >> m_source >> m_sink;

    // get rid of the extra new line left by previous line
    std::getline(graph_stream, line);

    construct_graph(graph_stream);

    assert(m_graph.size() == N);
}

void Graph::construct_graph(std::fstream &graph_stream) {
    for (std::string line; std::getline(graph_stream, line);) {
        construct_vertex(line);
    }
}

void Graph::construct_vertex(std::string &line) {
    std::istringstream is(line);
    std::vector<Weight> edges;
    Weight w;
    for (int i = 0; i < N; ++i) {
        is >> w;
        edges.push_back(w);
    }
    m_graph.push_back(std::move(edges));
}

void Graph::dump() {
    std::cout << N << std::endl;
    std::cout << m_source << " " << m_sink << std::endl;
    for (auto &v : m_graph) {
        for (auto &e : v)
            std::cout << e << " ";
        std::cout << std::endl;
    }
}

void Graph::set_size(unsigned n) {
    auto edge = std::vector<Weight>(n, 0);
    for (unsigned i = 0 ; i < n; ++i) {
        m_graph.push_back(edge);
    }
    N = n;
}

void Graph::set_source(Vertex s) {
    m_source = s;
}

void Graph::set_sink(Vertex t) {
    m_sink = t;
}

Vertex Graph::get_source() {
    return m_source;
}

Vertex Graph::get_sink() {
    return m_sink;
}

unsigned Graph::get_size() {
    return N;
}

void Graph::set_weight(Vertex u, Vertex v, Weight w) {
    m_graph[u][v] = w;
}

bool Graph::find_any_path(Vertex u, Vertex v, std::vector<Vertex> &p) {
    p.push_back(u);
    bool find = _find_any_path(u, v, p);
    if(!find) {
        p.clear();
    }
    return find;
}

bool Graph::_find_any_path(Vertex u, Vertex v, std::vector<Vertex> &p) {
    Vertex curr = p.back();
    bool find;

    if(curr == v)
        return true;

    assert(curr == u);

    for(int idx = 0; idx < N; ++idx) {
        Weight w = m_graph[curr][idx];
        if(w == WEIGHT_NONE)
            continue;
        if(path_has_vertex(p, idx))
            continue;
        p.push_back(idx);
        if(_find_any_path(idx, v, p))
            return true;
        p.pop_back();
    }
    return false;
}

// XXX: could use a hashmap to reduce the search
bool Graph::path_has_vertex(std::vector<Vertex> &p, Vertex v) {
    for(auto &vm : p) {
        if (vm == v)
           return true;
    }

    return false;
}

void Graph::apply_residual(std::vector<Vertex> &p) {
    // find the minimum capacity
    assert(!p.empty());
    Weight min_weight = WEIGHT_MAX;

    for(int i = 0; i < p.size() - 1; ++i) {
        Vertex u = p[i];
        Vertex v = p[i+1];
        if(m_graph[u][v] < min_weight)
            min_weight = m_graph[u][v];
    }

    // decrease the weight and increase the shrinkage
    for(int i = 0; i < p.size() - 1; ++i) {
        Vertex u = p[i];
        Vertex v = p[i+1];
        m_graph[u][v] -= min_weight;
        m_graph[v][u] += min_weight;
    }

    mincut += min_weight;
}

Weight Graph::get_mincut() {

    std::vector<Vertex> p;
    while(find_any_path(get_source(), get_sink(), p)) {
        apply_residual(p);
        p.clear();
    }

    return mincut;
}
