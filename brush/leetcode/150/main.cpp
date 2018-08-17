class Solution {
	public:
		bool isoperator(string token) {
			return token == "+" || token == "-" || token == "*" || token == "/";
		}
		int evalRPN(vector<string> &tokens) {
			stack<int> operands;
			for(auto& token : tokens) {
				if(isoperator(token)) {
					auto num1 = operands.top(); operands.pop();
					auto num2 = operands.top(); operands.pop();
					if(token == "+") {
						operands.push(num1 + num2);
					} else if (token == "-") {
						operands.push(num2 - num1);
					} else if (token == "*") {
						operands.push(num1 * num2);
					} else {
						operands.push(num2 / num1);
					}
				} else {
					operands.push(stoi(token));
				}
			}

			return operands.top();
		}
};

int main() {}
