//Используется тестовый фреймворк Catch. Интеграция Catch с CMake довольно проста, так как это только библиотека для заголовков.
//Можно сделать проект CMake зависимым от Catch с помощью find_package: в CMakeLists.txt добавляем: find_package(Catch REQUIRED).
//Особенности Catch: имена тестов (сценариев) - это обычные строки (т. к. имя теста нужно только для того чтобы один раз описать что он тестирует, 
//чтобы это описание потом записалось в лог с результатами тестирования);
#include "catch.hpp"//подключение библиотеки Catch.
#include "matrix.hpp"
SCENARIO("matrix new w/o params","[new w/o params]"){//тест (сценарий).
    Matrix matrix;
    REQUIRE(matrix.Rows() == 0);//проверка справедливости выражения.
    REQUIRE(matrix.Columns() == 0);
}

SCENARIO("matrix new with params","[new with params]"){
    Matrix matrix(3,3);
    REQUIRE(matrix.Rows() == 3);
    REQUIRE(matrix.Columns() == 3);
}

SCENARIO("matrix operator+","[oper+]"){
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");//имя файла должно быть коротким (иначе почему-то не производится запись в него).
    file1 << "1 2 2 2";//сериализация - тесты для ввода в поток.
    file1.close();
    ofstream file2("B.txt");
    file2 << "5 6 6 6";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    REQUIRE(matrix1.Element(0,0) + matrix2.Element(0,0) == 6);
    REQUIRE(matrix1.Element(0,1) + matrix2.Element(0,1) == 8);
    REQUIRE(matrix1.Element(1,0) + matrix2.Element(1,0) == 8);
    REQUIRE(matrix1.Element(1,1) + matrix2.Element(1,1) == 8);
}

SCENARIO("matrix operator-","[oper-]"){
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 2 2";
    file1.close();
    ofstream file2("B.txt");
    file2 << "5 6 6 6";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    REQUIRE(matrix2.Element(0,0) - matrix1.Element(0,0) == 4);
    REQUIRE(matrix2.Element(0,1) - matrix1.Element(0,1) == 4);
    REQUIRE(matrix2.Element(1,0) - matrix1.Element(1,0) == 4);
    REQUIRE(matrix2.Element(1,1) - matrix1.Element(1,1) == 4);
}

SCENARIO("matrix operator*", "[oper*]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 2 2";
    file1.close();
    ofstream file2("B.txt");
    file2 << "5 6 6 6";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,0) + matrix1.Element(0,1) * matrix2.Element(1,0) == 17);
    REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,1) + matrix1.Element(0,1) * matrix2.Element(1,1) == 18);
    REQUIRE(matrix1.Element(1,0) * matrix2.Element(0,0) + matrix1.Element(1,1) * matrix2.Element(1,0) == 22);
    REQUIRE(matrix1.Element(1,0) * matrix2.Element(0,1) + matrix1.Element(1,1) * matrix2.Element(1,1) == 24);
}

SCENARIO("matrix operator==" , "[oper==]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "2 2 2 2";
    file1.close();
    ofstream file2("B.txt");
    file2 << "2 2 2 2";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    for (int i = 0; i < matrix1.Rows(); i++)
    {
        for (int j = 0; j < matrix1.Columns(); j++)
        {
            REQUIRE(matrix1.Element(i,j) == matrix2.Element(i,j));
        }
    }

}

SCENARIO("matrix operator=" , "[oper=]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 2 2";
    file1.close();
    matrix1.Read("A.txt");
    matrix2 = matrix1;
    REQUIRE(matrix1.Element(0,0) == 1);
    REQUIRE(matrix1.Element(0,1) == 2);
    REQUIRE(matrix1.Element(1,0) == 2);
    REQUIRE(matrix1.Element(1,1) == 2);

}
