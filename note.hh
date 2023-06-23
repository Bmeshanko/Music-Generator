#include <bits/stdc++.h>
using namespace std;

class Note {
    short pitch;
    short octave;

    public:
        Note(short p) {
            pitch = p % 12;
            octave = p / 12;
        }
        
        short getPitch() {
            return pitch;
        }

        string toString() {
            switch (pitch) {
                case 0: return "E";
                case 1: return "F";
                case 2: return "Gb";
                case 3: return "G";
                case 4: return "Ab";
                case 5: return "A";
                case 6: return "Bb";
                case 7: return "B";
                case 8: return "C";
                case 9: return "Db";
                case 10: return "D";
                case 11: return "Eb";
            }
            return "";
        }
};

/*
*   Guitars are tuned where the lowest note is E, which we are setting to pitch 0.
*/

Note E = Note(0);
Note F = Note(1);
Note Gb = Note(2);
Note G = Note(3);
Note Ab = Note(4);
Note A = Note(5);
Note Bb = Note(6);
Note B = Note(7);
Note C = Note(8);
Note Db = Note(9);
Note D = Note(10);
Note Eb = Note(11);