// CodeWars - Pick Peaks
// https://www.codewars.com/kata/5279f6fe5ab7fb3bfc6000a5d
// This code identifies the positions and values of peaks in a numeric vector.
// A peak is defined as an element that is greater than its immediate neighbors.
// Plateaus (consecutive equal values) are considered peaks only if they are followed by a lower value.
#include <vector>

struct PeakData {
    std::vector<int> pos;
    std::vector<int> peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
    PeakData result;
    int size = v.size();
    if (size == 0) return result;

    for (int i = 1; i < size - 1; i++) {
        if (v[i] > v[i - 1]) {   // potential peak start
            int j = i + 1;
            // extend plateau
            while (j < size && v[j] == v[i]) j++;
            // check drop after plateau
            if (j < size && v[i] > v[j]) {
                result.pos.push_back(i);
                result.peaks.push_back(v[i]);
            }
            i = j - 1; // skip plateau
        }
    }
    return result;
}
