#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// the valuest book of programmer

// lcs

int lcsLength(const std::string& str1, const std::string& str2) {
    if(str1.empty() || str2.empty()) {
        return 0;
    }

    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            } else {
                table[i][j] = std::max(table[i-1][j], table[i][j-1]);
            }
         }
    }


    return table[m][n];
}

// dynamic plan transformer, from top to bottom
int lcsLengthT2b(const std::string& str1, const std::string& str2, int i, int j, vector<vector<int>>& table) {
    if(str1.empty() || str2.empty()) {
        return 0;
    }

    if(table.size() == 0) {
        int m = str1.size();
        int n = str2.size();

        table.resize(m + 1, vector<int>(n + 1, 0));
    }

    if(i == 0 || j == 0) {
        return table[i][j];
    }

    if(table[i][j] != 0) {
        return table[i][j];
    }

    if(str1[i-1] == str2[j-1]) {
        table[i][j] = lcsLengthT2b(str1, str2, i-1, j-1, table) + 1;
    } else {
        table[i][j] = std::max(lcsLengthT2b(str1, str2, i-1, j, table), lcsLengthT2b(str1, str2, i, j - 1, table));
    }

    return table[i][j];
}

vector<int> CustomAlgorithmTestcase::bestCoordinate(vector<vector<int> > &towers, int radius)
{
    auto signalIntensity = [&](vector<int>& pos, vector<int>& tower2) {
        int signal_intensity{0};

        float dist = sqrt(pow((pos[0] - tower2[0]), 2) + pow((pos[1] - tower2[1]), 2));

        if(dist <= radius) {
            signal_intensity = std::floor(tower2[2]/( 1 + dist));
        }

        return signal_intensity;
    };

    int m = towers.size();

    vector<int> signal_intensity_table(51*51, 0);

    for(int i = 0; i < m; i++) {
        // cur_tower, calculate intensity in the range of current tower
        int cur_tower_x = towers[i][0];
        int cur_tower_y = towers[i][1];
        int cur_tower_q = towers[i][2];

        // range
        int cur_tower_x_start = cur_tower_x - radius > 0 ? cur_tower_x - radius : 0;
        int cur_tower_x_end = cur_tower_x + radius < 50 ? cur_tower_x + radius : 50;

        int cur_tower_y_start = cur_tower_y - radius > 0 ? cur_tower_y - radius : 0;
        int cur_tower_y_end = cur_tower_y + radius < 50 ? cur_tower_y + radius : 50;

        for(int j = cur_tower_x_start; j <= cur_tower_x_end; j++) {
            for(int k = cur_tower_y_start; k <= cur_tower_y_end; k++) {
                vector<int> pos_temp{j, k};
                signal_intensity_table[j*51 + k] += signalIntensity(pos_temp, towers[i]);
            }
        }
    }

    // find the best
    vector<int> signal_table_ids(51*51);
    iota(signal_table_ids.begin(), signal_table_ids.end(), 0);

    auto Increase = [&](int idx1, int idx2) {
        return (signal_intensity_table[idx1] > signal_intensity_table[idx2]);
    };

    sort(signal_table_ids.begin(), signal_table_ids.end(), Increase);

    return {signal_table_ids[0]/51, signal_table_ids[0]%51};
 }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string str1{"ABCBDAB"};
    std::string str2{"BDCABA"};

//    std::cout << lcsLength(str1, str2) << std::endl;
    vector<vector<int>> table;
    std::cout << lcsLengthT2b(str1, str2, str1.size(), str2.size(), table) << std::endl;

    return a.exec();
}
