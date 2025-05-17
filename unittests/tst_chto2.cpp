#include <QtTest>
#include "C:\mpu_project-Server\server\include\functions_for_server.h"
// add necessary includes here

class chto2 : public QObject
{
    Q_OBJECT

public:
    chto2();
    ~chto2();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();

    void testDiaposons_BasicRange();
    void testDiaposons_ExactDivision();
    void testDiaposons_NotFullLastInterval();

    // Тесты для find_x
    void testFindX_NoRoots();
    void testFindX_SingleRoot();
    void testFindX_MultipleRoots();
    void testFindX_RootOnIntervalEdge();
    void testFindX_DoubleRoot();
    void testFindX_LinearFunction();
};

chto2::chto2() {}

chto2::~chto2() {}

void chto2::test_case1() {
    functions_for_server funcs;
    QCOMPARE(funcs.Calc(2, 3, 4, 5), 2*5*5 + 3*5 + 4);//обычный случай
}
void chto2::test_case2(){
    functions_for_server funcs;
    QCOMPARE(funcs.Calc(0, 3, 4, 5), 3*5 + 4);//случай а=0, то есть линейное уравнение
}
void chto2::test_case3(){
    functions_for_server funcs;
    QCOMPARE(funcs.Calc(2, 0, 4, 3), 2*3*3 + 4);//случай b=0, то есть ax² + c
}
void chto2::test_case4(){
    functions_for_server funcs;
    QCOMPARE(funcs.Calc(2, 3, 0, 4), 2*4*4 + 3*4);//случай c=0, то есть ax² + bx;
}
void chto2::test_case5(){
    functions_for_server funcs;
    QCOMPARE(funcs.Calc(0, 0, 0, 100), 0.0);//все коэффициенты нулевые
}
void chto2::test_case6(){
    functions_for_server funcs;
    QCOMPARE(funcs.Calc(-1, -2, -3, -4), -1*(-4)*(-4) + -2*(-4) + -3);//случай с отрицательными значениями
}
void chto2::testDiaposons_BasicRange() {
    functions_for_server funcs;
    auto result = funcs.diaposons(0.0, 1.0, 0.2);

    QCOMPARE(result.size(), 5);
    QVERIFY(qFuzzyCompare(result[0].first, 0.0));
    QVERIFY(qFuzzyCompare(result[0].second, 0.2));
    QVERIFY(qFuzzyCompare(result[4].first, 0.8));
    QVERIFY(qFuzzyCompare(result[4].second, 1.0));
}

void chto2::testDiaposons_ExactDivision() {
    functions_for_server funcs;
    auto result = funcs.diaposons(0.0, 1.0, 0.25);

    QCOMPARE(result.size(), 4);
    QVERIFY(qFuzzyCompare(result[3].first, 0.75));
    QVERIFY(qFuzzyCompare(result[3].second, 1.0));
}

void chto2::testDiaposons_NotFullLastInterval() {
    functions_for_server funcs;
    auto result = funcs.diaposons(0.0, 0.9, 0.3);

    QCOMPARE(result.size(), 3);
    QVERIFY(qFuzzyCompare(result[2].first, 0.6));
    QVERIFY(qFuzzyCompare(result[2].second, 0.9));
}
void chto2::testFindX_NoRoots() {
    functions_for_server funcs;
    auto intervals = funcs.diaposons(-5, 5, 1);
    auto result = funcs.find_x(intervals, 1, 0, 1); // x² + 1 = 0

    QVERIFY(result.isEmpty());
}

void chto2::testFindX_SingleRoot() {
    functions_for_server funcs;
    auto intervals = funcs.diaposons(-3, 3, 0.5);
    auto result = funcs.find_x(intervals, 1, 0, -4); // x² - 4 = 0

    QCOMPARE(result.size(), 2);
    QVERIFY(result.contains(2.0));
    QVERIFY(result.contains(-2.0));
}

void chto2::testFindX_MultipleRoots() {
    functions_for_server funcs;
    auto intervals = funcs.diaposons(-5, 5, 1);
    auto result = funcs.find_x(intervals, 1, -3, 2); // x² - 3x + 2 = 0

    QCOMPARE(result.size(), 2);
    QVERIFY(qFuzzyCompare(result[0], 1.0));
    QVERIFY(qFuzzyCompare(result[1], 2.0));
}

void chto2::testFindX_RootOnIntervalEdge() {
    functions_for_server funcs;

    // Случай 1: x=1 на правой границе
    QVector<QPair<double, double>> intervals1 = {{0.5, 1.0}, {1.0, 2.0}};
    auto result1 = funcs.find_x(intervals1, 1, -3, 2);
    QVERIFY(result1.contains(1.0)); // Проверяем корень на правой границе

    // Случай 2: x=1 на левой границе
    QVector<QPair<double, double>> intervals2 = {{1.0, 1.5}, {1.5, 2.0}};
    auto result2 = funcs.find_x(intervals2, 1, -3, 2);
    QVERIFY(result2.contains(1.0)); // Проверяем корень на левой границе

    // Общий случай (оба корня)
    QVector<QPair<double, double>> intervals3 = {{0.5, 1.5}, {1.5, 2.5}};
    auto result3 = funcs.find_x(intervals3, 1, -3, 2);
    QCOMPARE(result3.size(), 2); // Ожидаем два корня
    QVERIFY(result3.contains(1.0));
    QVERIFY(result3.contains(2.0));
}

void chto2::testFindX_DoubleRoot() {
    functions_for_server funcs;
    auto intervals = funcs.diaposons(0, 3, 0.5);
    auto result = funcs.find_x(intervals, 1, -4, 4); // x² - 4x + 4 = 0 (x=2)

    QCOMPARE(result.size(), 1);
    QVERIFY(qFuzzyCompare(result[0], 2.0));
}

void chto2::testFindX_LinearFunction() {
    functions_for_server funcs;
    auto intervals = funcs.diaposons(-5, 5, 1);
    auto result = funcs.find_x(intervals, 0, 1, -2); // x - 2 = 0

    QCOMPARE(result.size(), 1);
    QVERIFY(qFuzzyCompare(result[0], 2.0));
}
QTEST_APPLESS_MAIN(chto2)

#include "tst_chto2.moc"
