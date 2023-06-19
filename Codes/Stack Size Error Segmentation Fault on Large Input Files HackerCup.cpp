#include <sys/resource.h>
//include it at the beggining of the program

int main()
{
    //maybe it is only for linux
    //include these lines at the beggining of the main function
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));



    //for large input files, loading may be a problem
    //So read and write in this way, for faster processing...
    READ("running_on_fumes_chapter_2_input.txt");
    WRITE("running_on_fumes_chapter_2_output.txt");



    //YOUR CODE STARTS FROM HERE.........

    solve();








    return 0;
}
