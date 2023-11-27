#include <iostream>
#include <vector>

using namespace std;

vector<int> findIncreasingSubsequence(const vector<int>& sequence)
{
    int n = sequence.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sequence[i] > sequence[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++) 
    {
        if (dp[i] > maxLength) 
        {
            maxLength = dp[i];
        }
    }

    vector<int> result;
    int currentLength = maxLength;
    for (int i = n - 1; i >= 0; i--) 
    {
        if (dp[i] == currentLength)
        {
            result.push_back(sequence[i]);
            currentLength--;
        }
    }

    return result;
}

int main() 
{
    int N;
    cout << "Введите количество элементов последовательности: ";
    cin >> N;

    vector<int> sequence(N);
    cout << "Введите элементы последовательности:\n";
    for (int i = 0; i < N; i++) 
    {
        cin >> sequence[i];
    }

    vector<int> increasingSubsequence = findIncreasingSubsequence(sequence);

    cout << "Длина максимальной возрастающей подпоследовательности: " << increasingSubsequence.size() << endl;
    cout << "Максимальная возрастающая подпоследовательность: ";
    for (int i = increasingSubsequence.size() - 1; i >= 0; i--)
    {
        cout << increasingSubsequence[i];
        if (i != 0) {
            cout << ", ";
        }
    }
    cout << endl;
}