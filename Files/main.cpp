#if 0
Дан текстовый файл f. Записать в перевернутом виде строки файла f в файл g. Порядок строк в
файле g должен быть обратным по отношению к порядку строк исходного файла.
#endif

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("f.txt");
    ofstream g("g.txt");
    vector<string> lines;
    string str;
    while (getline(f, str)) {
        reverse(str.begin(), str.end());
        lines.push_back(str);
    }
    for (auto it = lines.begin(); it != lines.end(); ++it) {
        g << *it << endl;
    }
    f.close();
    g.close();
    return 0;
}