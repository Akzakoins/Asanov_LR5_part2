#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Asanov_MathTask.h"

void testGetFirstDigit()
{
    ASSERT_EQUAL(1, getFirstDigit(123));
    ASSERT_EQUAL(9, getFirstDigit(987));
    ASSERT_EQUAL(4, getFirstDigit(-456));
}

void testGetNthDigitFromRight()
{
    ASSERT_EQUAL(3, getNthDigitFromRight(123, 0)); // последний
    ASSERT_EQUAL(2, getNthDigitFromRight(123, 1)); // средний
    ASSERT_EQUAL(1, getNthDigitFromRight(123, 2)); // первый
}

void testInvalidThreeDigit()
{
    ASSERT(!isValidThreeDigit(99));
    ASSERT(!isValidThreeDigit(1000));
    ASSERT(isValidThreeDigit(123));
}

void testInvalidDigitPosition()
{
    ASSERT(!isValidDigitPosition(-1));
    ASSERT(!isValidDigitPosition(3));
    ASSERT(isValidDigitPosition(0));
    ASSERT(isValidDigitPosition(2));
}

bool runAllTests(int argc, char const *argv[])
{
    cute::suite s;
    s.push_back(CUTE(testGetFirstDigit));
    s.push_back(CUTE(testGetNthDigitFromRight));
    s.push_back(CUTE(testInvalidThreeDigit));
    s.push_back(CUTE(testInvalidDigitPosition));

    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<>> listener(xmlfile.out);
    return cute::makeRunner(listener)(s, "Все тесты");
}

int main(int argc, char const *argv[])
{
    return runAllTests(argc, argv) ? 0 : 1;
}
