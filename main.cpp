/* 
 * File:   main.cpp
 * Author: Akela1101
 *
 * Created on 11 Апрель 2011 г., 20:23
 */

#include <boost/filesystem.hpp>
#include <boost/array.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <set>

#include "../Nya.hpp"


using namespace std;
using namespace boost;
namespace fs = boost::filesystem;


bool CheckExtension(string ext, vector<string> extArray)
{
	foreach( const string &s, extArray )
	{
		if( ext == s )
			return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	vector<string> extensionSub = {".srt", ".sub", ".ass", ".ssa"};
	vector<string> extensionVideo = {".avi", ".mkv", ".wmv", ".mp4"};

	set<fs::path> subs, videos;
	
	fs::directory_iterator itr(fs::current_path()), end_itr;
	foreach( const fs::path &p, make_pair(itr, end_itr) )
	{
		if( CheckExtension(fs::extension(p), extensionSub) )
		{
			subs.insert(p);
		}
		else if( CheckExtension(fs::extension(p), extensionVideo) )
		{
			videos.insert(p);
		}
	}
	
	if( subs.size() != videos.size() )
	{
		cerr << "Numbers are wrong: subs( " << subs.size() << " ), "
			<< "videos( " << videos.size() << " )." << endl;
		return 1;
	}

	set<fs::path>::iterator iterSub, iterVideo, iterVideoEnd = videos.end();
	for( iterSub = subs.begin(), iterVideo = videos.begin();
			iterVideo != iterVideoEnd; ++iterSub, ++iterVideo )
	{
		string newSubName = iterVideo->stem().string() + iterSub->extension().string();
		cout << "Rename: " << iterSub->filename()
				<< " => " << newSubName << endl;
	}

	string reply;
	cout << endl << "Continue with it? (yes/no): ";
	cin >> reply;
	
	if( reply != "y" && reply != "yes" )
		return 0;

	for( iterSub = subs.begin(), iterVideo = videos.begin();
			iterVideo != iterVideoEnd; ++iterSub, ++iterVideo )
	{
		string newSubName = iterVideo->stem().string() + iterSub->extension().string();
		fs::rename(*iterSub, fs::path(newSubName));
	}

	return 0;
}

