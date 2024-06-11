#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int jmlSimpulBrianFarrelEvandhika_2311102037;
    cout << "Silahkan masukkan jumlah simpul = ";
    cin >> jmlSimpulBrianFarrelEvandhika_2311102037;

    vector<string> namaSimpulBrianFarrelEvandhika_2311102037(jmlSimpulBrianFarrelEvandhika_2311102037);
    vector<vector<int>> bobot(jmlSimpulBrianFarrelEvandhika_2311102037, vector<int>(jmlSimpulBrianFarrelEvandhika_2311102037));

    for (int i = 0; i < jmlSimpulBrianFarrelEvandhika_2311102037; ++i) {
        cout << "Silahkan masukkan nama simpul " << i + 1 << " = ";
        cin >> namaSimpulBrianFarrelEvandhika_2311102037[i];
    }

    cout << "Silahkan masukkan bobot antar simpul\n";

    for (int i = 0; i < jmlSimpulBrianFarrelEvandhika_2311102037; ++i) {
        for (int j = 0; jmlSimpulBrianFarrelEvandhika_2311102037 && j < jmlSimpulBrianFarrelEvandhika_2311102037; ++j) {
            cout << namaSimpulBrianFarrelEvandhika_2311102037[i] << "-->" << namaSimpulBrianFarrelEvandhika_2311102037[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "\n\t";
    for (int i = 0; i < jmlSimpulBrianFarrelEvandhika_2311102037; ++i) {
        cout << namaSimpulBrianFarrelEvandhika_2311102037[i] << "\t";
    }
    cout << "\n";

    for (int i = 0; i < jmlSimpulBrianFarrelEvandhika_2311102037; ++i) {
        cout << namaSimpulBrianFarrelEvandhika_2311102037[i] << "\t";
        for (int j = 0; j < jmlSimpulBrianFarrelEvandhika_2311102037; ++j) {
            cout << bobot[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
