#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int sum(const vector<int>& numbers)
{
    int answer = 0;
    for (int i : numbers)
    {
        answer += i;
    }
    return answer;
}

double average(const vector<int>& numbers)
{
    double answer = sum(numbers);
    numbers.size() ? answer = answer / numbers.size() : answer = 0.0;

    return answer;
}

void qsort(vector<int>& numbers, int left, int right, bool ascend = true)
{
    if (left >= right) 
    {
        return;
    }

    int pivot = numbers[left];
    int i = left + 1;
    int j = right;

    auto comp = [ascend](int a, int b) {
        return ascend ? a <= b : a >= b;
    };

    while (i <= j)
    {
        while (i <= right && comp(numbers[i], pivot)) {
            i++;
        }
        while (j > left && !comp(numbers[j], pivot)) {
            j--;
        }
        if (i < j) {
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[left], numbers[j]);

    qsort(numbers, left, j - 1, ascend);
    qsort(numbers, j + 1, right, ascend);
}


int main() {
    cout << "입력하실 숫자를 띄어쓰기 구분해서 입력해주세요.\n";

    string input;
    getline(cin, input);

    vector<int> numbers;
    stringstream ss(input);
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    qsort(numbers, 0 , numbers.size() - 1, true);
    cout << "오름차순 정렬: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    qsort(numbers, 0, numbers.size() - 1, false);
    cout << "내림차순 정렬: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    cout << "입력된 숫자들의 합계: ";
    cout << sum(numbers) << endl;

    cout << "입력된 숫자들의 평균: ";
    cout << average(numbers) << endl;

    return 0;
}
