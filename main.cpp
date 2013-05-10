/*
 * File:   main.cpp
 * Author: Akela1101
 *
 * Created on 11 Апрель 2011 г., 20:23
 */

#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <set>


using namespace std;
namespace fs = boost::filesystem;


int main(int argc, char* argv[])
{
	set<string> extensionSub = { ".srt", ".sub", ".ass", ".ssa" };
	set<string> extensionVideo = { ".avi", ".mkv", ".wmv", ".mp4" };

	set<fs::path> subs, videos;

	fs::directory_iterator end_it;
	for( fs::directory_iterator it(fs::current_path()); it != end_it; ++it )
	{
        const fs::path &p = *it;
        
		if( extensionSub.find(fs::extension(p)) != extensionSub.end() )
		{
			subs.insert(p);
		}
		else if( extensionVideo.find(fs::extension(p)) != extensionVideo.end() )
		{
			videos.insert(p);
		}
	}
	
	if( !videos.size() )
    {
        cout << "Try run this program in directory with video & subs." << endl;
        return 0;
    }

	if( subs.size() != videos.size() )
	{
		cerr << "Quantities don't match: subs( " << subs.size() << " ), "
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

	if( reply != "y" && reply != "yes" ) return 0;

	for( iterSub = subs.begin(), iterVideo = videos.begin();
			iterVideo != iterVideoEnd; ++iterSub, ++iterVideo )
	{
		string newSubName = iterVideo->stem().string() + iterSub->extension().string();
		fs::rename(*iterSub, fs::path(newSubName));
	}
	return 0;
}

