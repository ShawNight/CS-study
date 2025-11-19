#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<vector<string>> lines;
    string line;
    cout << "请输入二维数组内容（每行用空格分隔元素，Ctrl+D/Z 结束输入）:\n";

    while (getline(cin, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        vector<string> row;
        string element;

        while (iss >> element) {
            row.push_back(element);
        }

        if (!row.empty()) lines.push_back(row);
    }

    /* Started by AICoder, pid:l7be9se80ak8f471429f0a2410fd8d0195b85994 */
// 验证输出结果
    cout << "\n生成的二维数组内容：\n";
    for (const auto& row : lines) {
        for (const auto& elem : row) {
            cout << "\"" << elem << "\" ";
        }
        cout << endl;
    }
/* Ended by AICoder, pid:l7be9se80ak8f471429f0a2410fd8d0195b85994 */
    return 0;
}