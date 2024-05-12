/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mxM(int s[], int e[], int N) {
    vector<pair<int, int>> m;

    for (int i = 0; i < N; i++) {
        m.push_back({ e[i], s[i] });
    }

    sort(m.begin(), m.end());

    int c = 0;
    int lE = 0;

    for (int i = 0; i < N; i++) {
        if (m[i].second > lE) {
            c++;
            lE = m[i].first;
        }
    }

    return c;
}

int main() {
    int N1 = 6;
    int st1[] = { 1, 3, 0, 5, 8, 5 };
    int e1[] = { 2, 4, 6, 7, 9, 9 };
    cout << "Maximum number for example 1: " << mxM(st1, e1, N1) << endl;

    int N2 = 3;
    int st2[] = { 10, 12, 20 };
    int e2[] = { 20, 25, 30 };
    cout << "Maximum number for example 2: " << mxM(st2, e2, N2) << endl;

    return 0;
}

*/
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>  

using namespace std;

int findMaxTaskDeadline(const vector<tuple<int, int, int>>& taskList) {
    int maxDeadline = 0;
    for (const auto& task : taskList) {
        maxDeadline = max(maxDeadline, get<1>(task));
    }
    return maxDeadline;
}

vector<int> taskScheduling(int numTasks, vector<tuple<int, int, int>> tasks) {
    sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
        return get<2>(a) > get<2>(b);
        });

    int maxDeadline = findMaxTaskDeadline(tasks);
    vector<bool> timeSlots(maxDeadline + 1, false);

    int countTasks = 0, totalProfit = 0;

    for (int i = 0; i < numTasks; ++i) {
        for (int j = min(maxDeadline, get<1>(tasks[i])); j > 0; --j) {
            if (!timeSlots[j]) {
                timeSlots[j] = true;
                totalProfit += get<2>(tasks[i]);
                countTasks++;
                break;
            }
        }
    }

    return { countTasks, totalProfit };
}

int main() {
    vector<tuple<int, int, int>> tasks1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    auto result1 = taskScheduling(4, tasks1);
    cout << "Number of tasks done: " << result1[0] << ", Maximum profit: " << result1[1] << endl;

    vector<tuple<int, int, int>> tasks2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    auto result2 = taskScheduling(5, tasks2);
    cout << "Number of tasks done: " << result2[0] << ", Maximum profit: " << result2[1] << endl;

   return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
    int f, s;
};

int calcMaxChainLen(P arr[], int n) {
    sort(arr, arr + n, [](const P& a, const P& b) {
        return a.s < b.s;
    });

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].s < arr[i].f) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    P arr1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum length of chain is " << calcMaxChainLen(arr1, n1) << endl;

    P arr2[] = { {5, 10}, {1, 11} };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Maximum length of chain is " << calcMaxChainLen(arr2, n2) << endl;

    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
    int f, s;
};

int maxChainLength(P a[], int n) {
    sort(a, a + n, [](const P& x, const P& y) {
        if (x.f == y.f) return x.s < y.s;
        return x.f < y.f;
    });

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j].s < a[i].f && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    P a1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n1 = sizeof(a1) / sizeof(a1[0]);
    cout << "Maximum length of chain is " << maxChainLength(a1, n1) << endl;

    P a2[] = { {5, 10}, {1, 11} };
    int n2 = sizeof(a2) / sizeof(a2[0]);
    cout << "Maximum length of chain is " << maxChainLength(a2, n2) << endl;

    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct P {
    int x, y;
};

void explore(vector<vector<int>>& m, int x, int y, vector<string>& p, string path, int size) {
    if (x < 0 || x >= size || y < 0 || y >= size || m[x][y] == 0) return;
    if (x == size - 1 && y == size - 1) {
        p.push_back(path);
        return;
    }

    m[x][y] = 0; // Mark the cell as visited
    // Explore all possible directions
    if (x < size - 1) { // Move down
        explore(m, x + 1, y, p, path + 'D', size);
    }
    if (y < size - 1) { // Move right
        explore(m, x, y + 1, p, path + 'R', size);
    }
    if (x > 0) { // Move up
        explore(m, x - 1, y, p, path + 'U', size);
    }
    if (y > 0) { // Move left
        explore(m, x, y - 1, p, path + 'L', size);
    }
    m[x][y] = 1; // Unmark the cell
}

vector<string> findPaths(int s, vector<vector<int>>& m) {
    vector<string> p;
    if (m[0][0] == 1 && m[s - 1][s - 1] == 1) { // Check if start and end are accessible
        explore(m, 0, 0, p, "", s);
    }
    sort(p.begin(), p.end());
    return p;
}

int main() {
    int s1 = 4;
    vector<vector<int>> m1 = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<string> r1 = findPaths(s1, m1);
    if (r1.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& s : r1) {
            cout << s << " ";
        }
        cout << endl;
    }

    int s2 = 2;
    vector<vector<int>> m2 = { {1, 0}, {1, 0} };
    vector<string> r2 = findPaths(s2, m2);
    if (r2.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& s : r2) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <string>
using namespace std;

void expPathsUtil(vector<vector<int>>& m, int x, int y, string p, vector<string>& ps, vector<vector<bool>>& v) {
    int N = m.size();
    if (x < 0 || y < 0 || x >= N || y >= N || m[x][y] == 0 || v[x][y])
        return;

    if (x == N - 1 && y == N - 1) {
        ps.push_back(p);
        return;
    }

    v[x][y] = true;

    // Move down
    if (x + 1 < N && !v[x + 1][y] && m[x + 1][y] == 1)
        expPathsUtil(m, x + 1, y, p + 'D', ps, v);

    // Move right
    if (y + 1 < N && !v[x][y + 1] && m[x][y + 1] == 1)
        expPathsUtil(m, x, y + 1, p + 'R', ps, v);

    // Move left
    if (y - 1 >= 0 && !v[x][y - 1] && m[x][y - 1] == 1)
        expPathsUtil(m, x, y - 1, p + 'L', ps, v);

    v[x][y] = false;
}

vector<string> findPaths(vector<vector<int>>& m) {
    int N = m.size();
    vector<string> ps;
    vector<vector<bool>> v(N, vector<bool>(N, false));
    if (m[0][0] == 0)
        return ps; // No path if the starting cell is blocked
    expPathsUtil(m, 0, 0, "", ps, v);
    return ps;
}

int main() {
    vector<vector<int>> m1 = { {1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1} };
    vector<string> ps1 = findPaths(m1);
    if (ps1.empty())
        cout << "-1" << endl;
    else {
        for (const string& p : ps1)
            cout << p << " ";
        cout << endl;
    }

    vector<vector<int>> m2 = { {1, 0},
                               {1, 0} };
    vector<string> ps2 = findPaths(m2);
    if (ps2.empty())
        cout << "-1" << endl;
    else {
        for (const string& p : ps2)
            cout << p << " ";
        cout << endl;
    }

    return 0;
}
*/
/*#include <iostream>
#include <vector>
using namespace std;

bool iss(int v, vector<vector<int>>& g, vector<int>& c, int co) {
    for (int i = 0; i < g.size(); ++i) {
        if (g[v][i] && c[i] == co) return false;
    }
    return true;
}

bool pg(vector<vector<int>>& g, vector<int>& c, int m, int v) {
    int n = g.size();
    if (v == n) return true;

    for (int co = 1; co <= m; ++co) {
        if (iss(v, g, c, co)) {
            c[v] = co;
            if (pg(g, c, m, v + 1))
                return true;
            c[v] = 0;  // Backtrack
        }
    }
    return false;
}

int ccg(vector<vector<int>>& g, int m) {
    int n = g.size();
    vector<int> c(n, 0);
    return pg(g, c, m, 0) ? 1 : 0;
}

vector<vector<int>> cg(int N, const vector<pair<int, int>>& e) {
    vector<vector<int>> g(N, vector<int>(N, 0));
    for (auto& ed : e) {
        g[ed.first][ed.second] = 1;
        g[ed.second][ed.first] = 1; // Since the graph is undirected
    }
    return g;
}

int main() {
    // Example 1
    int N1 = 4, M1 = 3;
    vector<pair<int, int>> e1 = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };
    vector<vector<int>> g1 = cg(N1, e1);
    cout << "Example 1: " << ccg(g1, M1) << endl;

    // Example 2
    int N2 = 3, M2 = 2;
    vector<pair<int, int>> e2 = { {0, 1}, {1, 2}, {0, 2} };
    vector<vector<int>> g2 = cg(N2, e2);
    cout << "Example 2: " << ccg(g2, M2) << endl;

    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool valStr(string s) {
    int n = s.length();
    if (n > 3)
        return false;
    if (s[0] == '0' && n > 1)
        return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void genIP(string S, int pos, vector<string>& res, vector<string>& cur) {
    if (cur.size() == 4 && pos == S.length()) {
        res.push_back(cur[0] + '.' + cur[1] + '.' + cur[2] + '.' + cur[3]);
        return;
    }
    if (cur.size() == 4 || pos == S.length())
        return;

    for (int len = 1; len <= 3 && pos + len <= S.length(); ++len) {
        string p = S.substr(pos, len);
        if (valStr(p)) {
            cur.push_back(p);
            genIP(S, pos + len, res, cur);
            cur.pop_back();
        }
    }
}

vector<string> genValidIPs(string &S) {
    vector<string> res;
    if (S.length() < 4 || S.length() > 12)
        return {"-1"};
    vector<string> cur;
    genIP(S, 0, res, cur);
    if (res.empty())
        return {"-1"};
    return res;
}

int main() {
    string S = "99999999999";
    vector<string> res = genValidIPs(S);
    if (res.size() == 1 && res[0] == "-1")
        cout << "Output: -1" << endl;
    else {
        cout << "Output:";
        for (auto ip : res)
            cout << " " << ip;
        cout << endl;
    }

    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Structure to represent a Trie node
struct Tre {
    Tre* ch[26];
    bool ew;

    Tre() {
        for (int i = 0; i < 26; ++i)
            ch[i] = nullptr;
        ew = false;
    }
};

// Inserts a word into the Trie
void adW(Tre* r, string w) {
    Tre* c = r;
    for (char ch : w) {
        int idx = ch - 'A'; // Convert character to index
        if (!c->ch[idx])
            c->ch[idx] = new Tre();
        c = c->ch[idx];
    }
    c->ew = true;
}

// DFS function to search for words in the board
void srchW(vector<vector<char>>& b, int r, int c, Tre* r, string p, unordered_set<string>& res, vector<vector<bool>>& v) {
    if (r < 0 || r >= b.size() || c < 0 || c >= b[0].size() || v[r][c])
        return;

    int idx = b[r][c] - 'A';
    if (!r->ch[idx])
        return;

    p += b[r][c];
    if (r->ch[idx]->ew)
        res.insert(p);

    v[r][c] = true;

    // Move to all 8 adjacent cells
    int rM[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int cM[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; ++i)
        srchW(b, r + rM[i], c + cM[i], r->ch[idx], p, res, v);

    v[r][c] = false;
}

vector<string> bglW(vector<vector<char>>& b, vector<string>& d) {
    unordered_set<string> res;
    int rw = b.size();
    int cl = b[0].size();

    Tre* r = new Tre();
    for (string w : d)
        adW(r, w);

    vector<vector<bool>> v(rw, vector<bool>(cl, false));

    // Search for words starting from each cell in the board
    for (int i = 0; i < rw; ++i) {
        for (int j = 0; j < cl; ++j) {
            string p = "";
            srchW(b, i, j, r, p, res, v);
        }
    }

    vector<string> rs(res.begin(), res.end());
    return rs;
}

int main() {
    int R = 3, C = 3;
    vector<vector<char>> b = {{'G','I','Z'}, {'U','E','K'}, {'Q','S','E'}};
    int N = 4;
    vector<string> d = {"GEEKS", "FOR", "QUIZ", "GO"};

    vector<string> w = bglW(b, d);

    for (string wd : w)
        cout << wd << " ";
    cout << endl;

    return 0;
}
*/
/*#include <iostream>
#include <vector>

using namespace std;

int fndKth(int a1[], int a2[], int n, int m, int k) {
    int i = 0, j = 0, cnt = 0;
    int res;

    while (i < n && j < m && cnt < k) {
        if (a1[i] < a2[j])
            res = a1[i++];
        else
            res = a2[j++];
        cnt++;
    }

    if (cnt == k)
        return res;

    while (i < n && cnt < k) {
        res = a1[i++];
        cnt++;
    }
    while (j < m && cnt < k) {
        res = a2[j++];
        cnt++;
    }

    return res;
}

int main() {
    int a1[] = {2, 3, 6, 7, 9};
    int a2[] = {1, 4, 8, 10};
    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);
    int k = 5;

    cout << "Output: " << fndKth(a1, a2, n, m, k) << endl;

    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pos(int arr[], int n, int m, int mid) {
    int reqStud = 1;
    int allocatedPage = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > mid)
            return false;

        if (allocatedPage + arr[i] > mid) {
            reqStud++;
            allocatedPage = arr[i];
            if (reqStud > m)
                return false;
        } else {
            allocatedPage += arr[i];
        }
    }

    return true;
}

int minPage(int arr[], int n, int m) {
    if (n < m)
        return -1;

    int total = 0, maxPage = 0;

    for (int i = 0; i < n; ++i) {
        total += arr[i];
        maxPage = max(maxPage, arr[i]);
    }

    int low = maxPage, high = total, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (pos(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N = 3;
    int A[] = {15, 17, 20};
    int M = 2;

    cout << "Output: " << minPage(A, N, M) << endl;

    return 0;
}
*/