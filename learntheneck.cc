#include <bits/stdc++.h>
using namespace std;

string strs[] = {"E", "A", "D", "G", "B", "e"};
string notes[] = {"E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#"};
int intervals[] = {0, 5, 10, 15, 19, 24};

int main() {
    int str_rand = rand() % 6;
    int fret_rand = rand() % 22 + 1;
    while (fret_rand == 0 || fret_rand == 12) {
        fret_rand = rand() % 22 + 1;
    }

}