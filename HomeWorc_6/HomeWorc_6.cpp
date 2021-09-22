#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void DZ1()
{
	cout << "//===================================================[DZ1]===================================================//\n\n";
}
void DZ2()
{
	cout << "\n//===================================================[DZ2]===================================================//\n\n";
}
void DZ3()
{
	cout << "\n//===================================================[DZ3]===================================================//\n\n";
}
void DZ4()
{
	cout << "\n//===================================================[DZ4]===================================================//\n\n";
}
void DZ5()
{
	cout << "\n//===================================================[DZ5]===================================================//\n\n";
}
void END()
{
	cout << "\n\n//===================================================[END]===================================================//\n\n";
}
//===================================================[DZ2]===================================================//
// Создание матрицы
int** CreateMatrix(size_t n, size_t m)
{
    int** M = new int* [n];
    for (size_t i = 0; i < n; ++i)
    {
        M[i] = new int[m];
    }
    return M;
}
// Удаление матрицы
void DeleteMatrix(int** M, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        delete[] M[i];
    }
    delete[] M;
}
//===================================================[Вывод матрицы]===================================================//
void output(int** M, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout << "M[" << i << "][" << j << "] = ";
            std::cin >> M[i][j];
        }
    }
}
//============================[ заполнение матрицы случайными числами из диапазона [0, 99] ]============================//
void RandomNumer(int** m1, const size_t m2, const size_t m3)
{
    srand((unsigned int)time(0)); // инициализируем ПГСЧ

    for (size_t x = 0; x < m2; x++)
        for (size_t v = 0; v < m3; v++)
            m1[x][v] = rand() % 100; // присваиваем СЧ
}
//===================================================[Печать матрицы]===================================================//
void MatrixPrint(int** M, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout << M[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
//===================================================[DZ_3-4]===================================================//
void name_txt()
{
    string path = "path.txt";
    ofstream fout;
    fout.open(path);
    if (!fout.is_open())
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        string a;
        cin >> a;
        fout << a;
    }
    fout.close();
//+++++++++++++++++++++++++++++++++++//
    string path2 = "path2.txt";
    ofstream fout1;
    fout1.open(path2);
    if (!fout1.is_open())
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        string a;
        cin >> a;
        fout1 << a;
    }
    fout1.close();
}
//===================================================[DZ4]===================================================//
void UnitFail(ifstream& fin, ofstream& fout)
{
    string str;
    while (!fin.eof())
    {
        getline(fin, str);
        fout << str << endl;
    }
}

void UnitFail()
{
    cout << "Enter file name 1: ";
    string txt_1, txt_2, compound;
    cin >> txt_1;
    txt_1 += ".txt";
    cout << "Enter file name 2: ";
    cin >> txt_2;
    txt_2 += ".txt";
    cout << "Enter the name of the shared file: ";
    cin >> compound;
    compound += ".txt";

    ifstream file1(txt_1);
    ifstream file2(txt_2);
    ofstream file_с(compound);

    if (file1.is_open() && file2.is_open() && file_с.is_open())
    {
        UnitFail(file1, file_с);
        file1.close();

        UnitFail(file2, file_с);
        file2.close();

        file_с.close();
    }
}
//===================================================[DZ5]===================================================//
void ChekText()
{
    ifstream fin;
    fin.open("path2.txt");
    if (fin.is_open() == false)
    {
        cerr << "Error Unable to open file\n"; // не удается открыть файл
        exit(EXIT_FAILURE);
    }
    string item;
    cout << "Your text: ";
    while (getline(fin, item, '.'))
    {
        cout << item;
        item += '.';
    }
    cout << "\n";
    cout << "Enter the values yant to find! ";
    string word;
    cin >> word;
    {
        if (item.find(word) != string::npos)
        {
            cout << "Values found!";
        }
        else
        {
            cout << "No values found!";
        }
    }
    fin.close();
}

int main()
{
    {
        /* [DZ1]
        Выделить в памяти динамический одномерный массив
        типа int. Размер массива запросить у пользователя.
        Инициализировать его числами степенями двойки: 1, 2, 4,
        8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть
        освободить память. =) Разбить программу на функции.
        */
        DZ1();

        int* arRay;
        int n;
        cout << "Enter your values: ";
        cin >> n;
        arRay = new int[n];
        int temp = 1;
        cout << "Your values: ";
        for (size_t i = 0; i < n; i++)
        {
            arRay[i] = temp;
            cout << arRay[i] << " ";
            temp *= 2;
        }
        delete[] arRay;
    }

    {
        /* [DZ2]
        Динамически выделить матрицу 4х4 типа int.
        Инициализировать ее псевдослучайными числами через
        функцию rand. Вывести на экран. Разбейте вашу
        программу на функции которые вызываются из main.
        */
        DZ2();

        size_t n, m;

        // вводим размерность матрицы
        cout << "Enter the number of rows of the matrix: ";
        cin >> n;
        cout << "\nEnter the number of columns of the matrix: ";
        cin >> m;
        cout << "\n";

        // выделяем память под матрицу
        int** A = CreateMatrix(n, m);

        // ввод матрицы
        //Input( A, n, m );
        // заполнение случайными числами (вместо ввода)
        RandomNumer(A, n, m);

        // Вывод матрицы
        MatrixPrint(A, n, m);

        // освобождаем память, выделенную под матрицу и вектор
        DeleteMatrix(A, n);
    }

    {
        /* [DZ3]
        Написать программу, которая создаст два текстовых
        файла (*.txt), примерно по 50-100 символов в каждом
        (особого значения не имеет с каким именно содержимым).
        Имена файлов запросить у пользователя.
        */
        DZ3();

        string path2 = "path2.txt";
        ofstream fout1;
        fout1.open(path2);
        if (!fout1.is_open())
        {
            cout << "Error opening files!" << endl;
        }
        else
        {
            string a;
            cout << "Enter you text: ";
            cin >> a;
            fout1 << a;
        }
        fout1.close();

        string path = "path.txt";
        ofstream fout;
        fout.open(path);
        if (!fout.is_open())
        {
            cout << "Error opening files!" << endl;
        }
        else
        {
            string a;
            cout << "Enter you text: ";
            cin >> a;
            fout << a;
        }
        fout.close();
    }

    {
        /* [DZ4]
        Написать функцию, «склеивающую» эти файлы в
        третий текстовый файл (имя файлов спросить у
        пользователя).
        */
        DZ4();
        UnitFail();
    }

    {
        /* [DZ5]
        Написать программу, которая проверяет присутствует ли указанное пользователем
        при запуске программы слово в указанном пользователем файле
        (для простоты работаем только с латиницей).
        Используем функцию find которая есть в строках std::string.
        */
        DZ5();
        ChekText();
        END();
    }
    return 0;
}