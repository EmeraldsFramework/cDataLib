#include "../unit_testing.h"

static int a = 0;
static int b = 0;
static double double_value = 0.1;
static const char *random_string = "Thisstring";

void run_tests(void) {

describe("Test of the test library", {
    before({
        a = 7;
        b = 4;
    });

    it("should test check", {
        check(a == 7);
    });

    it("should fail to test check", {
        check(a != 7);
    });

    it("should test assert", {
        assert(a == 7, "\"a\" should be 7");
    });

    it("should fail to test assert", {
        assert(a != 7, "\"a\" should be != 7");
    });

    it("should test assert int eq", {
        assert_int_equality(4, b);
    });

    it("should fail to test assert int eq", {
        assert_int_equality(5, b);
    });

    it("should test assert double eq", {
        assert_double_equality(0.1, double_value);
    });

    it("should fail to test assert double eq", {
        assert_double_equality(0.2, double_value);
    });

    it("should test string eq", {
        assert_string_equality("Thisstring", random_string);
    });

    it("should fail to test string eq", {
        assert_string_equality("Thatstring", random_string);
    });
    
    it("should fail to test", {
        fail("Fail now!");
    });

    after();
});

describe("Test Lib 2", {
    it("should do some stuff with assert", {
        assert(2 == 2, "asserts 2 == 2");
    });

    it("should do more some stuff with assert", {
        assert(4 == 4, "asserts 4 == 4");
        assert(5 == 5, "asserts 5 == 5");
        assert(6 == 6, "asserts 6 == 6");
        assert(9 == 9, "asserts 9 == 9");
    });

    it("should fail at somethiing", {
        fail("ok");
    });
});

}

int main(void) {
    run_tests();
    print_passing_tests();
    print_failing_tests();
    report_time_taken_for_tests();
    return exit_code;
}