#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item 
{
	string name;
	int weight;
	int value;
};

bool cmp(Item a, Item b)
{
	return a.weight > b.weight;
}

int knapsack(int capacity, vector<Item>& items, vector<bool>& selected)
{

	sort(items.begin(), items.end(), cmp);

	int totalValue = 0;

	for (int i = 0; i < items.size(); i++) {

		Item item = items[i];

		if (capacity < item.weight) continue;

		totalValue += item.value;
		capacity -= item.weight;
		selected[i] = true;

		if (capacity <= 0) break;

	}

	return totalValue;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int capacity, n;
	cout << "Введите вместимость рюкзака: "; cin >> capacity;
	cout << "Введите кол-во предметов: "; cin >> n;

	vector<Item> items(n);
	cout << "Введите товары (имя, вес, стоимость)" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> items[i].name >> items[i].weight >> items[i].value;
	}

	vector<bool> selected(n, false);

	int result = knapsack(capacity, items, selected);
	cout << "Максимальная ценность: " << result << endl;

	cout << "В рюкзак положены: " << endl;

	for (int i = 0; i < n; i++)
	{
		if (selected[i])
		{
			cout << items[i].name << endl;
		}
	}

	return 0;
}