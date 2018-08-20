#include <vector>
#include <stack>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
	public:
		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			if(node == nullptr) return node;
			unordered_map<int, UndirectedGraphNode*> m;
			stack<UndirectedGraphNode*> s;
			m[node->label] = new UndirectedGraphNode(node->label);
			s.push(node);

			while(!s.empty()) {
				auto curr = s.top(); s.pop();
				auto copy = m[curr->label];
				for(auto neighbor : curr->neighbors) {
					if(m.find(neighbor->label) == m.end()) {
						m[neighbor->label] = new UndirectedGraphNode(neighbor->label);
						s.push(neighbor);
					}
					copy->neighbors.push_back(m[neighbor->label]);
				}
			}
			return m[node->label];
		}
};

int main() {}
