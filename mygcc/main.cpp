#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

void parse_cmd_args(int argc, char **argv, std::string &type, std::string &input, std::string &output)
{
    type = "link";
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == std::string("-c"))
        {
            type = "build";
            input = argv[i + 1];
        }
        if (argv[i] == std::string("-o"))
        {
            output = argv[i + 1];
        }
    }
}

void write_hostname(const std::string &output)
{
    printf("output: %s\n", output.c_str());
    char szHostName[256] = {0};
    gethostname(szHostName, 256);
    std::ofstream fout(output.c_str());
    if (fout.is_open())
    {
        fout << szHostName << std::endl;
        fout.close();
    }
    else
    {
        printf("write file fail #1: %s\n", output.c_str());
        exit(1);
    }
}

void write_out(int argc, char **argv, const std::string &output)
{
    std::ofstream fout(output.c_str());
    if (fout.is_open())
    {
        for (int i = 0; i < argc; i++)
        {
            if (argv[i] == "-o")
            {
                break;
            }

            std::ifstream stream(argv[i]);
            std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
            fout << "file: " << argv[i] << ", content: " << content << std::endl;
        }
        fout.close();
    }
    else
    {
        printf("write file fail #2: %s\n", output.c_str());
        exit(1);
    }
}

int main(int argc, char **argv)
{
    std::string type, input, output;
    parse_cmd_args(argc, argv, type, input, output);

    if (type == "build")
    {
        write_hostname(output);
    }
    else
    {
        write_out(argc, argv, output);
    }
}
