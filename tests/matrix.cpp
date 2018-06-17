#include "catch.hpp"
#include "matrix.hpp"
SCENARIO("matrix new w/o params","[new w/o params]"){
    Matrix matrix;
    REQUIRE(matrix.Rows() == 0);
    REQUIRE(matrix.Columns() == 0);
}

SCENARIO("matrix new with params","[new with params]"){
    Matrix matrix(3,3);
    REQUIRE(matrix.Rows() == 3);
    REQUIRE(matrix.Columns() == 3);
}

SCENARIO("matrix operator+","[oper+]"){
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("C:/Users/User/Documents/A1.txt");
    file1 << "1 2 2 2";
    file1.close();
    ofstream file2("C:/Users/User/Documents/B1.txt");
    file2 << "5 6 6 6";
    file2.close();
    matrix1.Read("C:/Users/User/Documents/A1.txt");
    matrix2.Read("C:/Users/User/Documents/B1.txt");
    REQUIRE(matrix1.Element(0,0) + matrix2.Element(0,0) == 6);
    REQUIRE(matrix1.Element(0,1) + matrix2.Element(0,1) == 8);
    REQUIRE(matrix1.Element(1,0) + matrix2.Element(1,0) == 8);
    REQUIRE(matrix1.Element(1,1) + matrix2.Element(1,1) == 8);
}

SCENARIO("matrix operator-","[oper-]"){
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("C:/Users/User/Documents/A1.txt");
    file1 << "1 2 2 2";
    file1.close();
    ofstream file2("C:/Users/User/Documents/B1.txt");
    file2 << "5 6 6 6";
    file2.close();
    matrix1.Read("C:/Users/User/Documents/A1.txt");
    matrix2.Read("C:/Users/User/Documents/B1.txt");
    REQUIRE(matrix2.Element(0,0) - matrix1.Element(0,0) == 4);
    REQUIRE(matrix2.Element(0,1) - matrix1.Element(0,1) == 4);
    REQUIRE(matrix2.Element(1,0) - matrix1.Element(1,0) == 4);
    REQUIRE(matrix2.Element(1,1) - matrix1.Element(1,1) == 4);
}

SCENARIO("matrix operator*", "[oper*]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("C:/Users/User/Documents/A1.txt");
    file1 << "1 2 2 2";
    file1.close();
    ofstream file2("C:/Users/User/Documents/B1.txt");
    file2 << "5 6 6 6";
    file2.close();
    matrix1.Read("C:/Users/User/Documents/A1.txt");
    matrix2.Read("C:/Users/User/Documents/B1.txt");
    REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,0) + matrix1.Element(0,1) * matrix2.Element(1,0) == 17);
    REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,1) + matrix1.Element(0,1) * matrix2.Element(1,1) == 18);
    REQUIRE(matrix1.Element(1,0) * matrix2.Element(0,0) + matrix1.Element(1,1) * matrix2.Element(1,0) == 22);
    REQUIRE(matrix1.Element(1,0) * matrix2.Element(0,1) + matrix1.Element(1,1) * matrix2.Element(1,1) == 24);
}

SCENARIO("matrix operator==" , "[oper==]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("C:/Users/User/Documents/A1.txt");
    file1 << "2 2 2 2";
    file1.close();
    ofstream file2("C:/Users/User/Documents/B1.txt");
    file2 << "2 2 2 2";
    file2.close();
    matrix1.Read("C:/Users/User/Documents/A1.txt");
    matrix2.Read("C:/Users/User/Documents/B1.txt");
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
    ofstream file1("C:/Users/User/Documents/A1.txt");
    file1 << "1 2 2 2";
    file1.close();
    matrix1.Read("C:/Users/User/Documents/A1.txt");
    matrix2 = matrix1;
    REQUIRE(matrix1.Element(0,0) == 1);
    REQUIRE(matrix1.Element(0,1) == 2);
    REQUIRE(matrix1.Element(1,0) == 2);
    REQUIRE(matrix1.Element(1,1) == 2);

}
