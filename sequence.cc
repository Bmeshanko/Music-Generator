#include <bits/stdc++.h>
#include "note.hh"
using namespace std;

typedef vector<Note> seq;

string print_tab(seq notes) {

}

seq pentatonic(Note root) {
    seq ret;

    int intervals[] = {0, 3, 5, 7, 10};

    int len = sizeof(intervals) / sizeof(intervals[0]);

    for (int i = 0; i < len; i++) {
        ret.push_back(Note((root.getPitch() + intervals[i]) % 12));
    }

    return ret;
}

int main() {
    seq song1 = pentatonic(A);
}