#include <QtTest>
#include "math_class.h"
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

void chto2::test_case1() { // x^2 - 5x + 6 = 0
    QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
    QVector<double> korni = math_class::find_x(ans, 1, -5, 6);
     QCOMPARE(korni[0], 2);//обычный случай
     QCOMPARE(korni[1], 3);//обычный случай
}
void chto2::test_case2(){ // x^2 + 4x + 4 = 0
   QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
   QVector<double> korni = math_class::find_x(ans, 1, 4, 4);
   QCOMPARE(korni[0], -2);
}
void chto2::test_case3() { // 2x^2 - 8x + 8 = 0
   QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
   QVector<double> korni = math_class::find_x(ans, 2, -8, 8);
   QCOMPARE(korni[0], 2);
}
void chto2::test_case4(){ // x^2 - 9 = 0
   //functions_for_server* funcs = functions_for_server::get_instance();
   QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
   QVector<double> korni = math_class::find_x(ans, 1, 0, -9);
   QCOMPARE(korni[0], -3);
   QCOMPARE(korni[1], 3);

}
void chto2::test_case5(){ // x^2 +1 + 1 = 0
   //functions_for_server* funcs = functions_for_server::get_instance();
   QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
   QVector<double> korni = math_class::find_x(ans, 1, 1, 1);
   QVERIFY(korni.isEmpty());
}
void chto2::test_case6() { // 3x + 6 = 0
   //functions_for_server* funcs = functions_for_server::get_instance();
   QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
   QVector<double> korni = math_class::find_x(ans, 0, 3, 6);
   QCOMPARE(korni[0], -2);
}
void chto2::testDiaposons_BasicRange() {
    auto result = math_class::diaposons(0.0, 1.0, 0.2);

    QCOMPARE(result.size(), 5);
    QVERIFY(qFuzzyCompare(result[0].first, 0.0));
    QVERIFY(qFuzzyCompare(result[0].second, 0.2));
    QVERIFY(qFuzzyCompare(result[4].first, 0.8));
    QVERIFY(qFuzzyCompare(result[4].second, 1.0));
}

void chto2::testDiaposons_ExactDivision() {
    auto result = math_class::diaposons(0.0, 1.0, 0.25);

    QCOMPARE(result.size(), 4);
    QVERIFY(qFuzzyCompare(result[3].first, 0.75));
    QVERIFY(qFuzzyCompare(result[3].second, 1.0));
}

void chto2::testDiaposons_NotFullLastInterval() {
    auto result = math_class::diaposons(0.0, 0.9, 0.3);

    QCOMPARE(result.size(), 3);
    QVERIFY(qFuzzyCompare(result[2].first, 0.6));
    QVERIFY(qFuzzyCompare(result[2].second, 0.9));
}
void chto2::testFindX_NoRoots() {
    auto intervals = math_class::diaposons(-5, 5, 1);
    auto result = math_class::find_x(intervals, 1, 0, 1); // x² + 1 = 0

    QVERIFY(result.isEmpty());
}

void chto2::testFindX_SingleRoot() {
    auto intervals = math_class::diaposons(-3, 3, 0.5);
    auto result = math_class::find_x(intervals, 1, 0, -4); // x² - 4 = 0

    QCOMPARE(result.size(), 2);
    QVERIFY(result.contains(2.0));
    QVERIFY(result.contains(-2.0));
}

void chto2::testFindX_MultipleRoots() {
    auto intervals = math_class::diaposons(-5, 5, 1);
    auto result = math_class::find_x(intervals, 1, -3, 2); // x² - 3x + 2 = 0

    QCOMPARE(result.size(), 2);
    QVERIFY(qFuzzyCompare(result[0], 1.0));
    QVERIFY(qFuzzyCompare(result[1], 2.0));
}

void chto2::testFindX_RootOnIntervalEdge() {
   //functions_for_server* funcs = functions_for_server::get_instance();

    // Случай 1: x=1 на правой границе
    QVector<QPair<double, double>> intervals1 = {{0.5, 1.0}, {1.0, 2.0}};
    auto result1 = math_class::find_x(intervals1, 1, -3, 2);
    QVERIFY(result1.contains(1.0)); // Проверяем корень на правой границе

    // Случай 2: x=1 на левой границе
    QVector<QPair<double, double>> intervals2 = {{1.0, 1.5}, {1.5, 2.0}};
    auto result2 = math_class::find_x(intervals2, 1, -3, 2);
    QVERIFY(result2.contains(1.0)); // Проверяем корень на левой границе

    // Общий случай (оба корня)
    QVector<QPair<double, double>> intervals3 = {{0.5, 1.5}, {1.5, 2.5}};
    auto result3 = math_class::find_x(intervals3, 1, -3, 2);
    QCOMPARE(result3.size(), 2); // Ожидаем два корня
    QVERIFY(result3.contains(1.0));
    QVERIFY(result3.contains(2.0));
}

void chto2::testFindX_DoubleRoot() {
    auto intervals = math_class::diaposons(0, 3, 0.5);
    auto result = math_class::find_x(intervals, 1, -4, 4); // x^2 - 4x + 4 = 0 (x=2)

    QCOMPARE(result.size(), 1);
    QVERIFY(qFuzzyCompare(result[0], 2.0));
}

void chto2::testFindX_LinearFunction() {
    auto intervals = math_class::diaposons(-5, 5, 1);
    auto result = math_class::find_x(intervals, 0, 1, -2); // x - 2 = 0

    QCOMPARE(result.size(), 1);
    QVERIFY(qFuzzyCompare(result[0], 2.0));
}
QTEST_APPLESS_MAIN(chto2)

#include "tst_chto2.moc"
