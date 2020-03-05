#ifndef __UNIT_TESTING_H_
#define __UNIT_TESTING_H_

#if defined(_WIN32)
    #include <Windows.h>
    #if defined(_MSC_VER) && _MSC_VER < 1900
        #define snprintf _snprintf
        #define __func__ __FUNCTION__
    #endif
#elif defined(__unix__) \
|| defined(__unix) \
|| defined(unix) \
|| defined(__APPLE__) \
&& defined (__MACH__)
    #if !defined(_POSIX_C_SOURCE) \
    || _POSIX_C_SOURCE < 200112L
        #undef _POSIX_C_SOURCE
        #define _POSIX_C_SOURCE 200112L
    #endif
    
    #include <unistd.h>
    #include <time.h>
    #include <sys/time.h>
    #include <sys/resource.h>
    #include <sys/times.h>
    #include <string.h>

    #define HAVE_POSIX_TIMER
    #ifdef CLOCK_MONOTONIC
        #define CLOCKID CLOCK_MONOTONIC
    #endif

    #if defined(__MACH__) && defined(__APPLE__)
        #define HAVE_MACH_TIMER
        #include <mach/mach.h>
        #include <mach/mach_time.h>
    #endif

    #if __GNUC__ >= 5 && !defined(__STDC_VERSION)
        #define __func__ __extension__ __FUNCTION__
    #endif
#else
    #error "Unknown OS"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/**
 * @param PASSING -> Set for passing tests
 * @param FAILING -> Set for failing tests
 **/
#define PASSING 1
#define FAILING 0

#define MAXIMUM_LENGTH_OF_RESULT_MESSAGE 1024
#define MAXIMUM_NUMBER_OF_TESTS 8192
#define FLOAT_COMPARISON_ACCURACY 1E-12

static int number_of_tests = 0;
static int number_of_asserts = 0;
static int number_of_failing_tests = 0;
static int status_of_test = FAILING;

/**
 * @param total_time_taken_for_tests -> The timer used to measure time to run tests
 * @param test_result_message -> The outcome returned from the test
 **/
static double total_time_taken_for_tests = 0;
static char test_result_message[MAXIMUM_LENGTH_OF_RESULT_MESSAGE];
static char name_of_tested_proc[1024];

/** Lists of tests outputs **/
static char *passing_tests[MAXIMUM_NUMBER_OF_TESTS] = {"0"};
static char *failing_tests[MAXIMUM_NUMBER_OF_TESTS] = {"0"};

/**
 * @macro: BLOCK
 * @desc: Expands to a do while loop that runs once
 *      Usefull for executing naked blocks
 * @param block -> The block of code to run
 **/
#define BLOCK(block) do { \
    block \
} while(0)

/**
 * @macro: before
 * @desc: Expands to a setup proc that gets executed before the tests
 * @param setup_proc -> The proc to run
 **/
#define before(setup_proc) BLOCK( \
    setup_proc; \
)

/**
 * @marco: after
 * @desc: Expands to a teardown proc that gets executed after the tests
 * @param teardown_proc -> The proc to run
 **/
#define after(teardown_proc) BLOCK( \
    teardown_proc; \
)

/**
 * @marco: describe
 * @desc: Expands to a block execution where tests are encompassed
 * @param object_name -> The name of the unit to describe
 * @param proc -> The proc to extend to
 **/
#define describe(object_name, proc) BLOCK( \
    printf("\033[38;5;205mDescribing: %s\033[0m\n", object_name); \
    proc; \
)

/**
 * @macro: it
 * @desc: Expands to a test run and saves all data gathered
 * @param proc_name -> The name of test to run
 * @param proc -> The actual test code
 **/
#define it(proc_name, proc) BLOCK( \
	status_of_test = FAILING; \
    snprintf(name_of_tested_proc, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, proc_name); \
    \
    double start_test_timer = get_timer(); \
    proc; \
    double end_test_timer = get_timer(); \
    \
	number_of_tests++; \
	if(!(status_of_test)) { \
		number_of_failing_tests++; \
        char *new_test_message = malloc(sizeof(test_result_message) + 1); \
        \
        snprintf(new_test_message, strlen(test_result_message) + 1, \
        test_result_message); \
        \
        failing_tests[number_of_failing_tests] = new_test_message; \
	} \
    else { \
        char *new_test_message = malloc(sizeof(test_result_message) + 1); \
        \
        snprintf(new_test_message, strlen(test_result_message) + 1, \
        test_result_message); \
        \
        passing_tests[number_of_tests - number_of_failing_tests] = new_test_message; \
    } \
    total_time_taken_for_tests += end_test_timer - start_test_timer; \
	fflush(stdout); \
)

/**
 * @macro: print_passing_tests
 * @desc: Prints all elements of the passing_tests list
 **/
#define print_passing_tests() BLOCK( \
    printf("\n"); \
    for(int i = 1; i <= number_of_tests - number_of_failing_tests; i++) { \
        printf("%s\n", passing_tests[i]); \
    } \
)

/**
 * @macro: print_failing_tests
 * @desc: Prints all elements of the failing_tests list
 **/
#define print_failing_tests() BLOCK( \
    printf("\n\n"); \
    for(int i = 1; i <= number_of_failing_tests; i++) { \
        printf("%s\n", failing_tests[i]); \
    } \
)

/** @param exit_code -> Used in return **/
#define exit_code number_of_failing_tests

/**
 * @macro: report_time_taken_for_tests
 * @desc: Report the number of tests, assertions and time taken while testing
 **/
#define report_time_taken_for_tests() BLOCK( \
	printf("\n\n→ %d tests\n\033[38;5;208m→ %d assertions\033[0m\n\033[1;32m→ %d passing\033[0m\n\033[1;31m→ %d failing\033[0m\n", \
    number_of_tests, number_of_asserts, \
    number_of_tests-number_of_failing_tests, number_of_failing_tests); \
    printf("\033[1;36m→ Finished in %.4f ms\033[0m\n", \
    total_time_taken_for_tests / 1000000.0); \
    \
)

/**
 * @macro: check
 * @desc: Asserts if a test proc is true or not
 * @param test -> The test proc to run
 **/
#define check(test) BLOCK( \
	number_of_asserts++; \
	if(!(test)) { \
		\
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;31m✗\033[0m it %s:\n    %s:%d:\n\t|> %s", \
        name_of_tested_proc, __FILE__, __LINE__, #test); \
		\
        status_of_test = FAILING; \
	} \
    else { \
        status_of_test = PASSING; \
        \
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;32m✓\033[0m it %s", name_of_tested_proc); \
    } \
)

/**
 * @macro: fail
 * @desc: Asserts a failing test and provides a message
 * @param message -> The message to output
 **/
#define fail(message) BLOCK( \
	number_of_asserts++; \
	\
    snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
    "\033[1;31m✗\033[0m it %s:\n    %s:%d:\n\t|> %s", \
    name_of_tested_proc, __FILE__, __LINE__, message); \
	\
    status_of_test = FAILING; \
)

/**
 * @macro: assert
 * @desc: Assert a test to be equal to a provided result
 * @param test -> The test proc to check
 * @param message -> A description of the expected result
 **/
#define assert(test, message) BLOCK( \
	number_of_asserts++; \
	if(!(test)) { \
        \
		snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;31m✗\033[0m it %s:\n    %s:%d:\n\t|> %s", \
        name_of_tested_proc, __FILE__, __LINE__, message); \
		\
        status_of_test = FAILING; \
	} \
    else { \
        status_of_test = PASSING; \
        \
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;32m✓\033[0m it %s", name_of_tested_proc); \
    } \
)

/**
 * @macro: assert_int_equality
 * @desc: Assert that the expected integer is equal to the result
 * @param expected -> The expected int
 * @param actual -> The actual value
 **/
#define assert_int_equality(expected, actual) BLOCK( \
	int temp_expected; \
	int temp_actual_value; \
	number_of_asserts++; \
	temp_expected = (expected); \
	temp_actual_value = (actual); \
	if(temp_expected != temp_actual_value) { \
        \
		snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;31m✗\033[0m it %s:\n    %s:%d:\n\t|> \"%d\" expected but got \"%d\"", \
        name_of_tested_proc, __FILE__, __LINE__, \
        temp_expected, temp_actual_value); \
        \
		status_of_test = FAILING; \
	} \
    else { \
        status_of_test = PASSING; \
        \
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;32m✓\033[0m it %s", name_of_tested_proc); \
    } \
)

/**
 * @macro: assert_double_equality
 * @desc: Assert that the expected double is equal to the result
 * @param expected -> The expected double
 * @param actual -> The actual value
 **/
#define assert_double_equality(expected, actual) BLOCK( \
	double temp_expected; \
	double temp_actual_value; \
	number_of_asserts++; \
	temp_expected = (expected); \
	temp_actual_value = (actual); \
	if(fabs(temp_expected - temp_actual_value) > FLOAT_COMPARISON_ACCURACY) { \
		int significant_figures = 1 - log10(FLOAT_COMPARISON_ACCURACY); \
		\
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;31m✗\033[0m it %s:\n    %s:%d:\n\t|> \"%.*g\" expected but got \"%.*g\"", \
        name_of_tested_proc, __FILE__, __LINE__, significant_figures, \
        temp_expected, significant_figures, temp_actual_value); \
        \
		status_of_test = FAILING; \
	} \
    else { \
        status_of_test = PASSING; \
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;32m✓\033[0m it %s", name_of_tested_proc); \
    } \
)

/**
 * @macro: assert_string_equality
 * @desc: Assert that the expected string is equal to the result
 * @param expected -> The expected string
 * @param actual -> The actual value
 **/
#define assert_string_equality(expected, actual) BLOCK( \
	const char *temp_expected = expected; \
	const char *temp_actual_value = actual; \
	number_of_asserts++; \
	if(!temp_expected) temp_expected = "NULL"; \
	if(!temp_actual_value) temp_actual_value = "NULL"; \
	if(strcmp(temp_expected, temp_actual_value)) { \
        \
		snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;31m✗\033[0m it %s:\n    %s:%d:\n\t|> \"%s\" expected but got \"%s\"", \
        name_of_tested_proc, __FILE__, __LINE__, \
        temp_expected, temp_actual_value); \
        \
		status_of_test = FAILING; \
	} \
    else { \
        status_of_test = PASSING; \
        \
        snprintf(test_result_message, MAXIMUM_LENGTH_OF_RESULT_MESSAGE, \
        "\033[1;32m✓\033[0m it %s", name_of_tested_proc); \
    } \
)

/**
 * @func: get_timer
 * @desc: A cross platform timer function for profiling
 * @return The time in nanoseconds
 **/
static uint64_t get_timer() {
    static uint64_t is_init = 0;
    #if defined(__APPLE__)
        static mach_timebase_info_data_t info;
        if (0 == is_init)
        {
            mach_timebase_info(&info);
            is_init = 1;
        }
        uint64_t now;
        now = mach_absolute_time();
        now *= info.numer;
        now /= info.denom;
        return now;
    #elif defined(__linux)
        static struct timespec linux_rate;
        if (0 == is_init)
        {
            clock_getres(CLOCKID, &linux_rate);
            is_init = 1;
        }
        uint64_t now;
        struct timespec spec;
        clock_gettime(CLOCKID, &spec);
        now = spec.tv_sec * 1.0e9 + spec.tv_nsec;
        return now;
    #elif defined(_WIN32)
        static LARGE_INTEGER win_frequency;
        if (0 == is_init)
        {
            QueryPerformanceFrequency(&win_frequency);
            is_init = 1;
        }
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (uint64_t)((1e9 * now.QuadPart) / win_frequency.QuadPart);
    #endif
}

#endif