#include "../unit_testing.h"

static int a = 0;
static int b = 0;
static double double_value = 0.1;
static const char *random_string = "Thisstring";

void run_tests(void) {
setup_test_data();

describe("Test of the test library", {
    before({
        a = 7;
        b = 4;
    });

    it("tests check", {
        check(a == 7);
    });

    it("fails to test check", {
        check(a != 7);
    });

    it("tests assert", {
        assert(a == 7, "\"a\" should be 7");
    });

    it("fails to test assert", {
        assert(a != 7, "\"a\" should be != 7");
    });

    it("tests assert int eq", {
        assert_int_equality(4, b);
    });

    it("fails to test assert int eq", {
        assert_int_equality(5, b);
    });

    describe("Describe inside describe", {
        it("does some stuff with assert", {
            assert(2 == 2, "asserts 2 == 2");
        });

        it("does more some stuff with assert", {
            assert(4 == 4, "asserts 4 == 4");
            assert(5 == 5, "asserts 5 == 5");
            assert(6 == 6, "asserts 6 == 6");
            assert(9 == 9, "asserts 9 == 9");
        });
        describe("Describe 3", {
        it("does some stuff with assert", {
            assert(2 == 2, "asserts 2 == 2");
        });

        it("does more some stuff with assert", {
            assert(4 == 4, "asserts 4 == 4");
            assert(5 == 5, "asserts 5 == 5");
            assert(6 == 6, "asserts 6 == 6");
            assert(9 == 9, "asserts 9 == 9");
        });

        it("fails at something", {
            fail("ok");
        });
    });

        it("fails at something", {
            fail("ok");
        });
    });

    it("tests assert double eq", {
        assert_double_equality(0.1, double_value);
    });

    it("fails to test assert double eq", {
        assert_double_equality(0.2, double_value);
    });

    it("tests string eq", {
        assert_string_equality("Thisstring", random_string);
    });

    it("fails to test string eq", {
        assert_string_equality("Thatstring", random_string);
    });
    
    it("fails to test", {
        fail("Fail now!");
    });

    after();
});

}

int main(void) {
    run_tests();
    report_test_results("both");
    report_time_taken_for_tests();
    return exit_code;
}