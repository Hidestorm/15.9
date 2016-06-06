#include "TextQuery.h"
#include "open_file.h"


string make_plural(size_t ctr, const string &word,
	const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}
void print_results(const set<TextQuery::line_no>& locs,
	const string& sought, const TextQuery &file)
{
	// if the word was found, then print count and all occurrences
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs "
		<< size << " "
		<< make_plural(size, "time", "s") << endl;
	// print each line in which the word appeared
	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it) {
		cout << "\t(line "
			// don't confound user with text lines starting at 0
			<< (*it) + 1 << ") "
			<< file.text_line(*it) << endl;
	}
}
int main()
{
	ifstream infile;
	string txt = "Text.txt";		//file name
	if ( !open_file(infile, txt))
	{
		cerr << "No input file!" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile); // builds query map
						  // iterate with the user: prompt for a word to find and print	results
		// loop indefinitely; the loop exit is inside the while
		while (true) {
			cout << "enter word to look for, or q to quit: ";
			string s;
			cin >> s;
			// stop if hit eof on input or a 'q'is entered
			if (!cin || s == "q") break;
			// get the set of line numbers on which this word appears
			set<TextQuery::line_no> locs = tq.run_query(s);
			// print count and all occurrences, if any
			print_results(locs, s, tq);
		}
		system("pause");
	return 0;
}

