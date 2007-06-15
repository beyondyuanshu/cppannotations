    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>

    class CaseString
    {
        public:
            bool operator()(std::string const &first,
                            std::string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) < 0;
            }
    };

    using namespace std;

    int main()
    {
        string  saints[] = {"Oh", "when", "the", "saints"};

        cout << "All previous permutations of 'Oh when the saints':\n";

        cout << "Sequences:\n";
        do
        {
            copy(saints, saints + 4, ostream_iterator<string>(cout, " "));
            cout << endl;
        }
        while (prev_permutation(saints, saints + 4, CaseString()));

        cout << "After first sorting the sequence:\n";
        sort(saints, saints + 4, CaseString());

        cout << "Sequences:\n";
        while (prev_permutation(saints, saints + 4, CaseString()))
        {
            copy(saints, saints + 4, ostream_iterator<string>(cout, " "));
            cout << endl;
        }
        cout << "No (more) previous permutations\n";

        return 0;
    }
    /*
        Generated output:

        All previous permutations of 'Oh when the saints':
        Sequences:
        Oh when the saints
        Oh when saints the
        Oh the when saints
        Oh the saints when
        Oh saints when the
        Oh saints the when
        After first sorting the sequence:
        Sequences:
        No (more) previous permutations
    */
