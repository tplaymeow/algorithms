#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point { 
    string name; 
    int count; 

    Point(string name) {
        this->name = name;
    }
};

struct Edge { Point *p1, *p2; };
struct Diagonal { Point *p1, *p2, *p3, *p4; };

string process_edge(Edge& edge) {
    string result;
    while (edge.p1->count && edge.p2->count) {
        edge.p1->count--;
        edge.p2->count--;
        result += edge.p1->name + edge.p2->name + "-" + "\n";
    }
    return result;
}

string process_diagonal(Diagonal& diagonal) {
    string result;
    while (diagonal.p1->count && diagonal.p4->count) {
        diagonal.p1->count--;
        diagonal.p4->count--;
        result += diagonal.p2->name + diagonal.p3->name + "+" + "\n";
        result += diagonal.p1->name + diagonal.p2->name + "-" + "\n";
        result += diagonal.p3->name + diagonal.p4->name + "-" + "\n";
    }
    return result;
}

int main() {
    Point A("A"), B("B"), C("C"), D("D"), E("E"), F("F"), G("G"), H("H");
    cin >> A.count 
        >> B.count 
        >> C.count 
        >> D.count 
        >> E.count 
        >> F.count 
        >> G.count 
        >> H.count;

    vector<Edge> edges {
        { &A, &B }, { &B, &C }, { &C, &D }, { &D, &A },
        { &E, &F }, { &F, &G }, { &G, &H }, { &H, &E },
        { &A, &E }, { &B, &F }, { &C, &G }, { &D, &H }
    };

    vector<Diagonal> diogonals {
        { &A, &E, &F, &G }, // A -> G
        { &B, &F, &E, &H }, // B -> H
        { &D, &H, &E, &F }, // D -> F
        { &C, &G, &F, &E }, // C -> E
    };

    string result;
    for (auto& edge : edges) {
        result += process_edge(edge);
    }
    for (auto& diagonal : diogonals) {
        result += process_diagonal(diagonal);
    }

    result = !A.count && !B.count && !C.count && !D.count && !E.count && !F.count && !G.count && !H.count
        ? result
        : "IMPOSSIBLE";
    cout << result;

    return 0;
}