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

void add_note(vcc &tab, short fret, short str) {
    // str - Low E = 0, High E = 5
    // fret - fret number of note
    vc dashes{'-', '-', '-', '-', '-', '-'};
    if (fret >= 10) {
        dashes[str] = '0' + (fret / 10);
        tab.push_back(dashes);
        vc dashes2{'-', '-', '-', '-', '-', '-'};
        dashes2[str] = '0' + (fret % 10);
        tab.push_back(dashes2);
    } else {
        dashes[str] = '0' + fret;
        tab.push_back(dashes);
    }
}

vcc new_tab(seq notes) {
    vcc tab;
    add_dashes(tab);

    short root = notes[0].getNote();
    // Root is on E String.
    // In the worst case the root will be played by the pointer
    // So we can only use our pinky which is 3 frets higher.
    short low = root - 2;
    short high = root + 3;
    int string_increments[] = {0, 5, 10, 15, 19, 24};
    for (auto n : notes) {
        short note = n.getNote();
        int i = 0;
        while (i < 6) {
            if ((note - string_increments[i]) >= low && (note - string_increments[i]) <= high) break;
            i++;
        }
        add_note(tab, note - string_increments[i], i);
        add_dashes(tab);
    }

    return tab;
}

void print_tab(vcc tab) {
    for (int i = tab[0].size() - 1; i >= 0; i--) {
        for (int j = 0; j < tab.size(); j++) {
            cout << tab[j][i];
        }
        cout << "\n";
    }
}

seq pentatonic(Note root) {
    seq ret;
    int intervals[] = {0, 3, 5, 7, 10, 12, 15, 17, 19, 22, 24, 27};
    int len = sizeof(intervals) / sizeof(intervals[0]);

    for (int i = 0; i < len; i++) {
        ret.push_back(Note((root.getNote() + intervals[i])));
    }

    return ret;
}

seq major_scale(Note root) {
    seq ret;

    int intervals[] = {0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19, 21, 23, 24};
    int len = sizeof(intervals) / sizeof(intervals[0]);

    ret.push_back(root);

    for (int i = 0; i < 10; i++) {
        int r = rand() % len;
        ret.push_back(Note((root.getNote() + intervals[r])));
    }
    
    return ret;
}

int main() {
    seq major = major_scale(Note(8));
    vcc tab = new_tab(major);
    print_tab(tab);
}