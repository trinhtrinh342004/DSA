// Đồ thị vô hướng
#include <iostream>
#include <map>
#include <queue>
#include <limits>
using namespace std;

// priority queue
typedef priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> min_heap;
/*
min_heap: kdl mới
priority_queue: hàng đợi ưu tiên, phần tử có giá trị ưu tiên cao hơn sẽ được xử lí trước
vector<pair<int, string> lưu trữ các phần tử
greater<pair<int, string>>: sắp xếp phần tử tăng dần
*/

// cost and vertex
typedef pair<int, string> vertex;
/*
vertex: kdl mới, cặp giá trị và chuỗi
*/

const int oo = numeric_limits<int>::max();
// lấy giá trị tối đa gán cho oo (vô cực)

map<string, map<string, int>> DIEM;
map<string, int> dist;


void dijkstra(string s) {
    min_heap pq;
    dist[s] = 0;
    // Đỉnh bắt đầu là s
    pq.push(vertex(0, s));
    // kc s tới s=0, đưa s vào priority queue vs giá trị ưu tiên = 0
    while (!pq.empty()) {
        string u = pq.top().second; //.second sử dụng để lấy tên (u) của đỉnh đó
        int cost_to_u = pq.top().first; // .first được 
        pq.pop(); // xóa phần tử đầu tiên tròn pq
        if (dist[u] == cost_to_u) // ktra đỉnh đc duyệt chưa = cách so sánh kc min từ đỉnh s ->u vs giá trị ưu tiên của u
        {
            for (auto v : DIEM[u])// v.first: tên của đỉnh kề, v.second: trọng số cạnh 
            {
                if (dist[v.first] > dist[u] + v.second) //kiểm tra xem khoảng cách từ đỉnh xuất phát đến đỉnh kề mới tính (dist[u] + v.second) có nhỏ hơn khoảng cách hiện tại (dist[v.first]) hay không
                {
                    dist[v.first] = dist[u] + v.second; //cập nhật khoảng cách ngắn nhất từ đỉnh xuất phát đến đỉnh kề v.first
                    pq.push(vertex(dist[v.first], v.first)); //thêm đỉnh kề v.first vào hàng đợi ưu tiên pq với giá trị ưu tiên là khoảng cách ngắn nhất từ đỉnh xuất phát đến đỉnh v.first.
                }
            }
        }
    }
}

// Đồ thị vô hướng
void add_edge(string u, string v, int c) {
    DIEM[u][v] = c;
    DIEM[v][u] = c;
}

// Đồ thị có hướng
//void add_edge(string u, string v, int c) {
  //  DIEM[u][v] = c;
//}

int main() {
    // Nhập dữ liệu
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }

    // Khởi tạo dist ban đầu
    for (auto p : DIEM) {
        dist[p.first] = oo;
    }

    // Chạy thuật toán Dijkstra
    string s;
    cin >> s;
    dijkstra(s);

    // In ra các khoảng cách ngắn nhất từ đỉnh s đến các đỉnh còn lại
    for (auto p : dist) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
