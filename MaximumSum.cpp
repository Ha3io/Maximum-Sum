#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> bubbleSort(std::vector<int> arrEx)
{
    std::vector<int> arr = arrEx;
    bool swapped;
    for (int i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return arr;
}

std::vector<int> maxSumArray(std::vector<int> a) {
    int in = 0;
    bool alone = false;
    std::vector<int> b;
    for (int i = 0; i < a.size(); i += 0) {
        if (a[i] == 0) {
            b.push_back(a[i]);
            in++;
            i++;
        }
        else if (a[i] == 1 && i == 0) {
            alone = true;
            in++;
            i++;
        }
        else if ((a[i] == 1 && i != 0)) {
            b.push_back(a[i]);
            alone = false;
            in++;
            i++;
        }
        else {
            b.push_back(a[i]);
            i += 2;
        }
    }
    if (alone) {
        in++;
    }
    if (a.size() % 2 != 0 && in % 2 == 0) {
        for (int i = a.size() - 2; 0 <= i; i -= 2) {
            if (a[i] == 0) {
                break;
            }
            if (a[i] == 1 && !alone) {
                b.push_back(a[i]);
                break;
            }
            b.push_back(a[i]);
        }
    }
    else {
        for (int i = a.size() - 1; 0 < i; i -= 2) {
            if (a[i] == 0) {
                break;
            }
            if (a[i] == 1 && !alone) {
                b.push_back(a[i]);
                break;
            }
            b.push_back(a[i]);
        }
    }
    return b;
}

int sumMulti(std::vector<int> a) {
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        sum += a[i] * a[i+1];
    }
    return sum;
}

int main() {
    int t;
    do {
        std::cin >> t;
    } while (t < 1 || t > 25);
    

    std::vector<std::pair<int, std::vector<int>>> result;

    int n;
    for (int i = 0; i < t;i++) {
        do {
            std::cin >> n;
        } while (n < 1 || n > 100000);
        std::vector<int> a;

        do {
            std::string input;
            std::getline(std::cin, input);

            std::istringstream iss(input);
            int number;

            while (iss >> number) {
                if (number < 0 || number > 100000) {
                    number = 0;
                }
                a.push_back(number);
            }
        }while(a.size() != n);
        

        a = bubbleSort(a);

        std::vector<int> b = maxSumArray(a);

        int sum = sumMulti(b);
        result.push_back(std::make_pair(sum, b));
        a.clear();
        b.clear();
    }

    for (int i = 0; i < t; i++) {
        std::cout << result[i].first << std::endl;
        for (int j = 0; j < result[i].second.size(); j++) {
            std::cout << result[i].second[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
