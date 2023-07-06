#include <bits/stdc++.h>
using namespace std;

string strs[] = {"E", "A", "D", "G", "B", "e"};
string notes[] = {"E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#"};
int intervals[] = {0, 5, 10, 15, 19, 24};

int main() {
    srand((unsigned) time(NULL));
    int starttime = time(NULL);
    int correct = 0;
    int n = 10;
    for (int i = 0; i < n; i++) {
        int str = rand() % 6;
        int fret = rand() % 22 + 1;
        while (fret == 0 || fret == 12) {
            fret = rand() % 22 + 1;
        }

        cout << strs[str] << " string, fret " << fret << "\n";
        int note = (intervals[str] + fret) % 12;
        string input;
        cin >> input;
        if (input == notes[note]) {
            correct++;
        }
    }
    int endtime = time(NULL);
    cout << correct << "/" << n << " correct\n";
    cout << endtime - starttime << " seconds\n";
}