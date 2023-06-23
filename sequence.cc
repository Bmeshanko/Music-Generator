#include <bits/stdc++.h>
#include "note.hh"
using namespace std;

typedef vector<Note> seq;
typedef vector<char> vc;
typedef vector<vc> vcc;

void print_notes(seq notes) {
    for (int i = 0; i < notes.size(); i++) {
        cout << notes[i].toString() << " ";
    }
    cout << "\n";
}

void add_dashes(vcc &tab) {
    vc dashes{'-', '-', '-', '-', '-', '-'};
    tab.push_back(dashes);
}

vcc new_tab(seq notes) {
    vcc tab;
    add_dashes(tab);

    for (auto n : notes) {
        
    }

    return tab;
}

void print_tab(vcc tab) {
    for (int i = 0; i < tab[0].size(); i++) {
        for (int j = 0; j < tab.size(); j++) {
            cout << tab[j][i];
        }
        cout << "\n";
    }
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
    seq song1 = pentatonic(E);
    vcc tab = new_tab(song1);
    print_tab(tab);
}