#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

template <typename T>
void swap_my(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

class fmatrix {
private:
    size_t rows, cols;
    double** data;

    void memeger() { // управление памятью
        if (data) {
            for (size_t i = 0; i < rows; ++i) delete[] data[i];
            delete[] data;
        }
        data = nullptr;
    }

public:
    // Конструктор по умолчанию
    fmatrix() : rows(0), cols(0), data(nullptr) {}

    // Конструктор с размерами
    fmatrix(size_t r, size_t c) : rows(r), cols(c) {
        if (r == 0 || c == 0) {
            cout << "Размеры матрицы должны быть положительными" << endl;
            return;
        }
        data = new double*[rows];
        for (size_t i = 0; i < rows; ++i) data[i] = new double[cols]{0};
    }

    // Конструктор копирования (сущ)
    fmatrix(const fmatrix& other) : rows(other.rows), cols(other.cols) {
        data = new double*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (size_t j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    // Оператор присваивания
    fmatrix& operator=(const fmatrix& other) {
        if (this == &other) return *this;
        memeger();
        rows = other.rows;
        cols = other.cols;
        data = new double*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (size_t j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
        return *this;
    }

    // Деструктор
    ~fmatrix() { memeger(); }

    // Доступ к элементам
    double& operator()(size_t r, size_t c) {
        if (r < 1 || r > rows || c < 1 || c > cols) return data[0][0];
        return data[r-1][c-1];
    }

    const double& operator()(size_t r, size_t c) const {
        if (r < 1 || r > rows || c < 1 || c > cols) return data[0][0];
        return data[r-1][c-1];
    }

    // Получение числа строк и столбцов
    size_t row_cnt() const { return rows; }
    size_t col_cnt() const { return cols; }

    // Унарные операторы + и -
    fmatrix operator+() const { return *this; }
    fmatrix operator-() const {
        fmatrix res(*this);
        for (size_t i = 1; i <= rows; ++i)
            for (size_t j = 1; j <= cols; ++j)
                res(i,j) = -res(i,j);
        return res;
    }

    // Бинарные + и -
    fmatrix operator+(const fmatrix& B) const {
        if (rows != B.rows || cols != B.cols) return fmatrix();
        fmatrix res(rows, cols);
        for (size_t i = 1; i <= rows; ++i)
            for (size_t j = 1; j <= cols; ++j)
                res(i,j) = (*this)(i,j) + B(i,j);
        return res;
    }

    fmatrix operator-(const fmatrix& B) const {
        if (rows != B.rows || cols != B.cols) return fmatrix();
        fmatrix res(rows, cols);
        for (size_t i = 1; i <= rows; ++i)
            for (size_t j = 1; j <= cols; ++j)
                res(i,j) = (*this)(i,j) - B(i,j);
        return res;
    }

    // Умножение матриц
    fmatrix operator*(const fmatrix& B) const {
        if (cols != B.rows) return fmatrix();
        fmatrix res(rows, B.cols);
        for (size_t i = 1; i <= rows; ++i)
            for (size_t j = 1; j <= B.cols; ++j)
                for (size_t k = 1; k <= cols; ++k)
                    res(i,j) += (*this)(i,k) * B(k,j);
        return res;
    }

    // swap_rows и swap_cols
    void swap_rows(size_t r1, size_t r2) {
        if (r1 < 1 || r1 > rows || r2 < 1 || r2 > rows) return;
        swap_my(data[r1-1], data[r2-1]);
    }

    void swap_cols(size_t c1, size_t c2) {
        if (c1 < 1 || c1 > cols || c2 < 1 || c2 > cols) return;
        for (size_t i = 0; i < rows; ++i)
            swap_my(data[i][c1-1], data[i][c2-1]);
    }

    // Вывод матрицы
    friend std::ostream& operator<<(std::ostream& os, const fmatrix& M) {
        for (size_t i = 1; i <= M.rows; ++i) {
            for (size_t j = 1; j <= M.cols; ++j)
                os << M(i,j) << "\t";
            os << endl;
        }
        return os;
    }

    // Решение СЛАУ методом Гаусса с выбором главного элемента
    fmatrix solve_gauss(const fmatrix& B) const {
        if (rows != cols || B.rows != rows) return fmatrix();
        size_t n = rows;
        fmatrix A(*this);
        fmatrix X(B);
        size_t* ind = new size_t[n];
        for (size_t i = 0; i < n; ++i) ind[i] = i;

        // Прямой ход
        for (size_t c = 1; c <= n; ++c) {
            size_t r_max = c, c_max = c;
            double max_val = 0;
            for (size_t i = c; i <= n; ++i)
                for (size_t j = c; j <= n; ++j)
                    if (fabs(A(i,j)) > max_val) { max_val = fabs(A(i,j)); r_max = i; c_max = j; }

            if (max_val == 0) { delete[] ind; return fmatrix(); }

            if (r_max != c) A.swap_rows(c,r_max), X.swap_rows(c,r_max);
            if (c_max != c) A.swap_cols(c,c_max);
            swap_my(ind[c-1], ind[c_max-1]);

            double diag = A(c,c);
            for (size_t j = c; j <= n; ++j) A(c,j) /= diag;
            for (size_t j = 1; j <= X.cols; ++j) X(c,j) /= diag;

            for (size_t i = c+1; i <= n; ++i) {
                double factor = A(i,c);
                for (size_t j = c; j <= n; ++j) A(i,j) -= factor*A(c,j);
                for (size_t j = 1; j <= X.cols; ++j) X(i,j) -= factor*X(c,j);
            }
        }

        // Обратный ход
        for (int i = int(n); i >= 1; --i)
            for (int j = i-1; j >= 1; --j) {
                double factor = A(j,i);
                for (size_t k = 1; k <= X.cols; ++k)
                    X(j,k) -= factor*X(i,k);
            }

        // Восстановление порядка переменных
        fmatrix X_final(n, X.cols);
        for (size_t i = 1; i <= n; ++i)
            for (size_t j = 1; j <= X.cols; ++j)
                X_final(ind[i-1]+1,j) = X(i,j);

        delete[] ind;
        return X_final;
    }
};

int main() {
    setlocale(LC_ALL, ".1251");

    fmatrix A(6,6);
    A(1,1)=3;  A(1,2)=-1; A(1,4)=2;  A(1,6)=-1;
    A(2,1)=2;  A(2,2)=4;  A(2,3)=-1; A(2,5)=1;
    A(3,2)=-3; A(3,3)=3;  A(3,4)=-1; A(3,6)=2;
    A(4,1)=1;  A(4,3)=2;  A(4,4)=4;  A(4,5)=-2;
    A(5,2)=1;  A(5,4)=-3; A(5,5)=5;  A(5,6)=-1;
    A(6,1)=2;  A(6,3)=-1; A(6,5)=1;  A(6,6)=3;

    fmatrix B(6,6);
    B(1,1)=1; B(1,2)=2; B(1,3)=0; B(1,4)=-1; B(1,5)=1; B(1,6)=0;
    B(2,1)=0; B(2,2)=1; B(2,3)=1; B(2,4)=2;  B(2,5)=0; B(2,6)=1;
    B(3,1)=1; B(3,2)=0; B(3,3)=2; B(3,4)=0;  B(3,5)=1; B(3,6)=1;
    B(4,1)=2; B(4,2)=1; B(4,3)=0; B(4,4)=1;  B(4,5)=2; B(4,6)=0;
    B(5,1)=0; B(5,2)=1; B(5,3)=2; B(5,4)=1;  B(5,5)=0; B(5,6)=1;
    B(6,1)=1; B(6,2)=0; B(6,3)=1; B(6,4)=0;  B(6,5)=1; B(6,6)=2;

    cout << "A:\n" << A << endl;
    cout << "B:\n" << B << endl;
    cout << "-------------------------------------------" << endl;

    fmatrix C = A + B;
    cout << "A + B:\n" << C << endl;

    fmatrix E = A * B;
    cout << "A * B:\n" << E << endl;
    cout << "-------------------------------------------" << endl;
    
    fmatrix D = -A;
    cout << "-A:\n" << D << endl;

    cout << "B:\n" << B << endl;

    B.swap_rows(1,2);
    cout << "B.swap_rows(1,2):\n" << B << endl;

    B.swap_cols(1,2);
    cout << "B.swap_cols(1,2):\n" << B << endl;

    fmatrix F(6,1);
    F(1,1)=4;
    F(2,1)=10;
    F(3,1)=-3;
    F(4,1)=5;
    F(5,1)=7;
    F(6,1)=8;

    fmatrix X = A.solve_gauss(F);
    cout << "-------------------------------------------" << endl;
    cout << "Решение СЛАУ:\n" << X << endl;
    system("pause");
}