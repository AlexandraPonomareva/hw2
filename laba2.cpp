#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Функция для инициализации векторов дефолтными значениями
void defaulttttt(std::vector<std::string>& imena, std::vector<int>& bali) {
    // Пример дефолтных значений
    imena = { "Alisa", "Boris", "Kirill", "Dmitriy", "Eva", "Fyodor", "Grisha", "Elena", "Ivan", "Stepan" };
    bali = { 91, 84, 93, 77, 92, 86, 94, 88, 85, 96 };
}

// Функция для инициализации векторов случайными значениями
void random(std::vector<std::string>& imena, std::vector<int>& bali, int size) {
    // Здесь можно добавить генерацию случайных имен из словаря реалистичных имен
    // Заполнение вектора оценок случайными значениями от 0 до 100
    for (int i = 0; i < size; ++i) {
        bali.push_back(rand() % 101);
    }
}

// Функция для инициализации векторов значениями, введенными пользователем
void uesrinput(std::vector<std::string>& imena, std::vector<int>& bali) {
    int size;
    std::cout << "Enter the number of students: ";
    std::cin >> size;
    std::cout << "Enter student imena and bali:\n";
    for (int i = 0; i < size; ++i) {
        std::string name;
        int grade;
        std::cout << "Student name " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Student assessment " << i + 1 << ": ";
        std::cin >> grade;
        imena.push_back(name);
        bali.push_back(grade);
    }
}

// Функция для вывода содержимого векторов с использованием range-based for-loop
void vectorrange(const std::vector<std::string>& imena, const std::vector<int>& bali) {
    std::cout << "Students and their bali (range-based for-loop):\n";
    for (const auto& name : imena) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    for (const auto& grade : bali) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

// Функция для вывода содержимого векторов с использованием итератора
void vectoriterator(const std::vector<std::string>& imena, const std::vector<int>& bali) {
    std::cout << "Students and their bali (iterator):\n";
    for (auto it = imena.begin(); it != imena.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (auto it = bali.begin(); it != bali.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Функция для вывода содержимого векторов с использованием обычного индексового цикла
void vectorindex(const std::vector<std::string>& imena, const std::vector<int>& bali) {
    std::cout << "Students and their bali (index cycle):\n";
    for (int i = 0; i < imena.size(); ++i) {
        std::cout << imena[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < bali.size(); ++i) {
        std::cout << bali[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для подсчета среднего значения оценок
double averageee(const std::vector<int>& bali) {
    int sum = 0;
    for (int grade : bali) {
        sum += grade;
    }
    return static_cast<double>(sum) / bali.size();
}

// Функция для нахождения медианы оценок
double mediannn(std::vector<int> bali) {
    std::sort(bali.begin(), bali.end());
    if (bali.size() % 2 == 0) {
        return (bali[bali.size() / 2 - 1] + bali[bali.size() / 2]) / 2.0;
    }
    else {
        return bali[bali.size() / 2];
    }
}

// Функция для нахождения моды оценок
std::vector<std::string> mode(const std::vector<std::string>& imena, const std::vector<int>& bali) {
    std::map<int, int> countMap; // Хранение числа повторений каждой оценки
    std::vector<std::string> modeimena; // Здесь будем хранить имена студентов с модной оценкой
    int maxCount = 0;

    for (int grade : bali) {
        countMap[grade]++;
        maxCount = std::max(maxCount, countMap[grade]);
    }

    // Поиск студентов с модной оценкой
    for (int i = 0; i < bali.size(); ++i) {
        if (countMap[bali[i]] == maxCount) {
            modeimena.push_back(imena[i]);
        }
    }
    return modeimena;
}

int main() {
    std::vector<std::string> imena;
    std::vector<int> bali;
    int choice;
    std::cout << "Select the vector initialization option:\n";
    std::cout << "1. default values\n";
    std::cout << "2. Random values\n";
    std::cout << "3. User input\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        defaulttttt(imena, bali);
        break;
    case 2:
        int size;
        std::cout << "Enter sample size: ";
        std::cin >> size;
        random(imena, bali, size);
        break;
    case 3:
        uesrinput(imena, bali);
        break;
    defaulttttt:
        std::cout << "Wrong choice. The program will be completed.\n";
        return 0;
    }

    // Вывод содержимого векторов
    vectorrange(imena, bali); // Используется range-based for-loop

    // Расчет и вывод среднего значения
    double average = averageee(bali);
    std::cout << "average ratings: " << averageee << std::endl;

    // Расчет и вывод медианы
    double median = mediannn(bali);
    std::cout << "median ratings: " << mediannn << std::endl;

    // Расчет и вывод моды
    std::vector<std::string> modeimena = mode(imena, bali);
    std::cout << "Fashion grade students:\n";
    for (const auto& name : modeimena) {
        std::cout << name << std::endl;
    }

    return 0;
}
