#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void hanoiTower(int n, int source, int auxiliary, int target, vector<string>& actions)
{
    if (n == 1)
    {
        actions.push_back("Переместить диск 1 с " + to_string(source) + " на " + to_string(target) + " стержень");
        return;
    }

    hanoiTower(n - 1, source, target, auxiliary, actions);
    actions.push_back("Переместить диск " + to_string(n) + " с " + to_string(source) + " на " + to_string(target) + " стержень");
    hanoiTower(n - 1, auxiliary, source, target, actions);
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    int N, k;
    cout << "Введите количество дисков (N): ";
    cin >> N;
    cout << "Введите количество стержней (k): ";
    cin >> k;

    if (N < 1 || k < 3) 
    {
        cout << "Неправильные значения. Количество дисков должно быть больше 0, а количество стержней не менее 3." << endl;
        return 1;
    }

    vector<string> actions;
    hanoiTower(N, 1, 2, k, actions);

    cout << "Последовательность действий:" << endl;
    for (const string& action : actions)
    {
        cout << action << endl;
    }
}
