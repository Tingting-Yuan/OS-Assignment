#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TMPFILE "tmp_output.txt"
#define BUFFER 1024

// Run a command and capture its output to TMPFILE
void run_program(const char *cmd) {
    char full_cmd[BUFFER];
    snprintf(full_cmd, sizeof(full_cmd), "%s > %s 2>&1", cmd, TMPFILE);
    int ret = system(full_cmd);
    if (ret != 0) {
        printf("Warning: Command '%s' exited with code %d\n", cmd, ret);
    }
}

// Check if TMPFILE contains the expected string
int output_contains(const char *expected) {
    FILE *fp = fopen(TMPFILE, "r");
    if (!fp) {
        perror("fopen");
        return 0;
    }
    char line[BUFFER];
    int found = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, expected)) {
            found = 1;
            break;
        }
    }
    fclose(fp);
    return found;
}

// Test cases
void test_normal_run() {
    run_program("./posix/pthreads_example 5");
    assert(output_contains("Hello from thread 0"));
    assert(output_contains("Hello from thread 1"));
    assert(output_contains("Hello from thread 2"));
    assert(output_contains("Hello from thread 3"));
    assert(output_contains("Hello from thread 4"));
    assert(output_contains("All threads completed."));
    printf("✅ test_normal_run passed\n");
}

void test_missing_parameter() {
    run_program("./posix/pthreads_example");
    assert(output_contains("Error: Wrong number of parameters."));
    printf("✅ test_missing_parameter passed\n");
}

void test_invalid_thread_count() {
    run_program("./posix/pthreads_example 0");
    assert(output_contains("Too few threads. Please specify a number greater than zero."));
    printf("✅ test_invalid_thread_count passed\n");
}

void test_normal_run2() {
    run_program("./posix/pthreads_example 2");
    assert(output_contains("Hello from thread 0"));
    assert(output_contains("Hello from thread 1"));
    assert(output_contains("All threads completed."));
    printf("✅ test_normal_run passed\n");
}

void test_invalid_thread_count2() {
    run_program("./posix/pthreads_example a");
    assert(output_contains("Too few threads. Please specify a number greater than zero."));
    printf("✅ test_invalid_thread_count passed\n");
}

int main() {
    test_normal_run();
    test_missing_parameter();
    test_invalid_thread_count();
    test_normal_run2();
    test_invalid_thread_count2();
    printf("\nAll tests passed!\n");
    // remove temporary file
    remove(TMPFILE);
    return 0;
}

