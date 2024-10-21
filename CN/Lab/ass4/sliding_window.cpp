#include <iostream>
#include <vector>
using namespace std;

class Protocol {
public:
    virtual void transmit(vector<int>& frames, int windowSize) = 0;
};

class GoBackN : public Protocol {
public:
    void transmit(vector<int>& frames, int windowSize) {
        int i = 0, ack;
        while (i < frames.size()) {
            for (int j = i; j < i + windowSize && j < frames.size(); j++) 
                cout << "Frame " << frames[j] << " sent\n";

            cout << "Enter last acknowledged frame: ";
            cin >> ack;

            if (ack == i + windowSize - 1) i += windowSize;
            else i = ack + 1;
        }
    }
};

class SelectiveRepeat : public Protocol {
public:
    void transmit(vector<int>& frames, int windowSize) {
        int ack[100] = {0};
        int i = 0, a;

        while (i < frames.size()) {
            for (int j = i; j < i + windowSize && j < frames.size(); j++)
                if (!ack[j]) cout << "Frame " << frames[j] << " sent\n";

            cout << "Enter acknowledged frame: ";
            cin >> a;
            ack[a] = 1;

            while (i < frames.size() && ack[i]) i++;
        }
    }
};

int main() {
    vector<int> frames = {1, 2, 3, 4, 5, 6};
    int windowSize;
    cout << "Enter window size: ";
    cin >> windowSize;

    GoBackN gbn;
    cout << "\nGo-Back-N Transmission:\n";
    gbn.transmit(frames, windowSize);

    SelectiveRepeat sr;
    cout << "\nSelective Repeat Transmission:\n";
    sr.transmit(frames, windowSize);

    return 0;
}
