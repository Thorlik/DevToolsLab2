#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool lines_bool = false;
bool words_bool = false;
bool bytes_bool = false;
bool chars_bool = false;

void BytesCounter(const std::string& key) {
    std::ifstream fileb(key);
    fileb.seekg(0, std:: ios::end);
    size_t file_size = fileb.tellg();
    std::cout << "bytes " << file_size << " ";
}

void WordsCounter(const std::string& key) {
    int words = 0;
    bool in_word = false;
    int	c;
    std::ifstream file(key);
    while ((c = file.get()) != EOF) {
        if (isspace(c)) {
            in_word = false;
        }
        else {
            if (! in_word) {
                in_word = true;
                words++;
            }
        }
    }
    std::cout << "words " << words << " ";
}

void LinesCounter(const std::string& key) {
    int	lines = 1;
    int	c;
    int counter = 0;

    std::ifstream file(key);

    while ((c = file.get()) != EOF)
    {
        counter++;
        switch (c)
        {
            case '\n':
                lines++;
        }
    }

    if (counter == 0){
        lines = 0;
    }
    std::cout << "lines " << lines << " ";
}

void CharsCounter(const std::string& key) {

    int	chars = 0;
    int	c;

    std::ifstream file(key);

    while ((c = file.get()) != EOF)
    {
        chars++;
        if (isspace(c)){
            chars--;
        }
    }
    std::cout << "chars " << chars << " ";
}

int main(int argc, char* argv[]) {

    const std::string& kOptionLines ("--lines");
    const std::string& kOptionBytes ("--bytes");
    const std::string& kOptionWords ("--words");
    const std::string& kOptionChars ("--chars");

    std::vector<std::string> filenames;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-') {
                std::string str0 (argv[i]);
                if (str0 == kOptionLines) {
                    lines_bool = true;
                }
                if (str0 == kOptionBytes) {
                    bytes_bool = true;
                }
                if (str0 == kOptionWords) {
                    words_bool = true;
                }
                if (str0 == kOptionChars) {
                    chars_bool = true;
                }
            }
            if (argv[i][1] == 'l') {
                lines_bool = true;
            }
            if (argv[i][1] == 'c') {
                bytes_bool = true;
            }
            if (argv[i][1] == 'w') {
                words_bool = true;
            }
            if (argv[i][1] == 'm') {
                chars_bool = true;
            }
        }
        else {
            FILE* f = fopen(argv[i], "r");
            if (f == nullptr) {
                printf("File %s can't be open\n",
                       argv[i]);
                return 1;
            }
            filenames.push_back(argv[i]);
        }
    }

    if (argc == 1) {
        std::cerr << "No input found" << std::endl;
        return 1;
    }

    if (argc > 1 && !lines_bool && !words_bool && !bytes_bool && !chars_bool) {
        std::cout << "lines bytes words chars " << std::endl;
    }

    for (int i = 0; i < filenames.size(); i++) {

        if (lines_bool) {
            LinesCounter(filenames[i]);
        }

        if (bytes_bool) {
            BytesCounter(filenames[i]);
        }

        if (words_bool) {
            WordsCounter(filenames[i]);
        }

        if (chars_bool) {
            CharsCounter(filenames[i]);
        }
        std::cout << " " << filenames[i] << std::endl;
    }

    return 0;
}