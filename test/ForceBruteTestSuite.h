#ifndef EXAMPLE_TEST_SUITE
#define EXAMPLE_TEST_SUITE

#include <cpptest.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "FetcherTest.h"
#include "GameModelControllerTest.h"
#include "LoaderTest.h"
#include "RuleFetcherTest.h"
#include "scene/AnimationTest.h"

using namespace std;


class ForceBruteTestSuite : public Test::Suite
{
    public:
        ForceBruteTestSuite()
        {

        }
                                
};

static void
usage()
{
    cout << "usage: mytest [MODE]\n"
         << "where MODE may be one of:\n"
         << "  --compiler\n"
         << "  --html\n"
         << "  --text-terse (default)\n"
         << "  --text-verbose\n";
    exit(0);
}


static auto_ptr<Test::Output>
cmdline(int argc, char* argv[])
{
    if (argc > 2)
        usage(); // will not return

    Test::Output* output = 0;

    if (argc == 1)
        output = new Test::TextOutput(Test::TextOutput::Verbose);
    else
    {
        const char* arg = argv[1];
        if (strcmp(arg, "--compiler") == 0)
            output = new Test::CompilerOutput;
        else if (strcmp(arg, "--html") == 0)
            output =  new Test::HtmlOutput;
        else if (strcmp(arg, "--text-terse") == 0)
            output = new Test::TextOutput(Test::TextOutput::Terse);
        else if (strcmp(arg, "--text-verbose") == 0)
            output = new Test::TextOutput(Test::TextOutput::Verbose);
        else
        {
            cout << "invalid commandline argument: " << arg << endl;
            usage(); // will not return
        }
   }
   return auto_ptr<Test::Output>(output);
}


int main(int argc, char* argv[])
{
    try
    {
        // Demonstrates the ability to use multiple test suites
        //
        Test::Suite ts;
        ts.add(auto_ptr<Test::Suite>(new FetcherTest));
        ts.add(auto_ptr<Test::Suite>(new GameModelControllerTest));
        ts.add(auto_ptr<Test::Suite>(new LoaderTest));
				ts.add(auto_ptr<Test::Suite>(new RuleFetcherTest));
				ts.add(auto_ptr<Test::Suite>(new AnimationTest));
        // Run the tests
        //
        auto_ptr<Test::Output> output(cmdline(argc, argv));
        ts.run(*output, true);

        Test::HtmlOutput* const html = dynamic_cast<Test::HtmlOutput*>(output.get());
        if (html)
            html->generate(cout, true, "MyTest");
    }
    catch (...)
    {
        cout << "unexpected exception encountered\n";
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;


}


#endif
